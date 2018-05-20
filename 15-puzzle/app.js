
//---Image Movement Globals---//
//Store whether board is currently loaded or not
var loaded = 0;
//Represent the positions of the images in an array
var original_positions = [1, 3, 4, 0, 5, 2, 7, 8, 9, 6, 11, 12, 13, 10, 14, 15];
var positions = [1, 3, 4, 0, 5, 2, 7, 8, 9, 6, 11, 12, 13, 10, 14, 15];

//-----Gameplay Semantics-----//
//Store the image selection
var option;
//Store whether the user has won on the current board or not, if so then
//disable any attempt to move the tiles
var won = 0;
var sorted = 1;

//--------Board + Leaderboard Globals-----//
//Clear the history of the leaderboard, will be an option
var clear_history = 0;
//Store the number of current tries taken on the board
var tries = 0;
//Store the amount of time taken on the current board
var begin;
//Store leaderboard
var leaderboard = new Array();

//Onload Function
$(document).ready(function() {
  //Implement scrolling features
  $("#scroll-to-play").click(function() {
    $('html, body').animate({
      scrollTop: $("#page2").offset().top
    }, 1000);
  });
  $("#leaderboard-link").click(function() {
    $('html, body').animate({
      scrollTop: $("#page3").offset().top
    }, 1000);
  });
  //Load the leaderboard
  retrieve_leaderboard();
  load_leaderboard();
  //Set the unload function to store the current leaderboard changes
});

//Load Images into place
function loadimages() {
  var board =
    "<table id=\"playing-board\">" +
    "  <tr> " +
    "    <td class=\"tiles\"><img id=\"1\" class=\"images\" onclick=\"move(this)\"></td> " +
    "    <td class=\"tiles\"><img id=\"3\" class=\"images\" onclick=\"move(this)\"></td> " +
    "    <td class=\"tiles\"><img id=\"4\" class=\"images\" onclick=\"move(this)\"></td> " +
    "    <td class=\"tiles\"><img id=\"0\" class=\"images\" onclick=\"move(this)\"></td> " +
    "  </tr> " +
    "  <tr> " +
    "    <td class=\"tiles\"><img id=\"5\" class=\"images\" onclick=\"move(this)\"></td> " +
    "    <td class=\"tiles\"><img id=\"2\" class=\"images\" onclick=\"move(this)\"></td> " +
    "    <td class=\"tiles\"><img id=\"7\" class=\"images\" onclick=\"move(this)\"></td> " +
    "    <td class=\"tiles\"><img id=\"8\" class=\"images\" onclick=\"move(this)\"></td> " +
    "  </tr> " +
    "  <tr> " +
    "    <td class=\"tiles\"><img id=\"9\" class=\"images\" onclick=\"move(this)\"></td> " +
    "    <td class=\"tiles\"><img id=\"6\" class=\"images\" onclick=\"move(this)\"></td> " +
    "    <td class=\"tiles\"><img id=\"11\" class=\"images\" onclick=\"move(this)\"></td> " +
    "    <td class=\"tiles\"><img id=\"12\" class=\"images\" onclick=\"move(this)\"></td> " +
    "  </tr> " +
    "  <tr> " +
    "    <td class=\"tiles\"><img id=\"13\" class=\"images\" onclick=\"move(this)\"></td> " +
    "    <td class=\"tiles\"><img id=\"10\" class=\"images\" onclick=\"move(this)\"></td> " +
    "    <td class=\"tiles\"><img id=\"14\" class=\"images\" onclick=\"move(this)\"></td> " +
    "    <td class=\"tiles\"><img id=\"15\" class=\"images\" onclick=\"move(this)\"></td> " +
    " " +
    "        </section> " +
    "        </td> " +
    "      </tr> " +
    "    </table> ";
  $("#board").html(board);
  option = $("#category option:selected").text().toLowerCase();
  for (var i = 1; i < 16; i++) {
    $("#" + i).attr("src", "images/" + option + "/image" + i + ".jpg");
  }
  $("#new-game-form").remove();
  var restart_button = "<div id=\"restart\">  " +
    "<button type=\"button\" id=\"restart-button\" class=\"btn btn-link\" onclick=\"restartBoard()\"> " +
    "  <p class=\"play-game-text\">Restart</p> " +
    "  </button> " +
    "  </div>";
  $("#board").append(restart_button);
  $("#leaderboard-link").css("margin-top", "120px");
  //Update globals
  begin = new Date();
  loaded = 1;
  tries = 0;
  won = 0;
  positions = original_positions.slice(0);
}

//Helper function to find and get indexes
function findIndex(id) {
  for (let i = 0; i < 16; i++) {
    if (positions[i] === id) {
      return i;
    }
  }
  return -1;
}

function getIndex(row, col) {
  return (row * 4) + col;
}

//Move adjacent element
function move(image) {
  if (loaded && !won) {
    var id = parseInt(image.id);
    var index = findIndex(id);
    var row = parseInt(index / 4);
    var col = index % 4;
    var found = -1;
    if (row < 3 && positions[getIndex(row + 1, col)] == 0) {
      found = getIndex(row + 1, col);
    } else if (col < 3 && positions[getIndex(row, col + 1)] == 0) {
      found = getIndex(row, col + 1);
    } else if (col > 0 && positions[getIndex(row, col - 1)] == 0) {
      found = getIndex(row, col - 1);
    } else if (row > 0 && positions[getIndex(row - 1, col)] == 0) {
      found = getIndex(row - 1, col);
    }
    if (found != -1) {
      tries++;
      positions[found] = id;
      positions[index] = 0;
      var a = $("#0");
      var b = $("#" + id);
      var tmp = $('<span>').hide();
      a.before(tmp);
      b.before(a);
      tmp.replaceWith(b);
      if (hasWon()) {
        winning_procedure();
      }
    }
  }
}

//Winning functions
function hasWon() {
  for (let i = 0; i < 14; i++) {
    if (positions[i] > positions[i + 1]) {
      return false;
    }
  }
  return true;
}

function winning_procedure() {
  insert_leaderboard(sorted);
  load_leaderboard();
  store_leaderboard();
  //update global
  won = 1;
  $("#0").parent().append("<h1 id=\"winning-message\">You Won!</h1>");
  $("#0").remove();
  positions = original_positions.slice(0);
}

function restartBoard() {
  if (won) {
    $("#winning-message").remove();
  }
  var form = "<div class=\"form-group center-block\" id=\"new-game-form\">" +
    "    <label id=\"category-select-header\">Select A Category</label> " +
    "    <select class=\"form-control\" id=\"category\"> " +
    "    <option>Nature</option> " +
    "    <option>Lion</option> " +
    "    <option>Boston</option> " +
    "    <option>Sports</option> " +
    "    <option>Lehigh</option> " +
    "  </select> " +
    "    <button type=\"button\" class=\"btn btn-primary\" id=\"start-game-button\" onclick=\"loadimages()\">Start New Game</button> " +
    "  </div> ";
  $("#playing-board").remove();
  $("#restart").remove();
  $(form).insertBefore("#board");
  $("#leaderboard-link").css("margin-top", "-300px");
  positions = original_positions.slice(0);
  loaded = 0;
  won = 0;
  tries = 0;
}


class LeaderboardEntry {
  constructor(date, attempts, time) {
    this.date = date;
    this.attempts= attempts;
    this.time = time;
  }
}

function sortByTries() {
  var swapped;
  for (var i = 0; i < leaderboard.length - 1; i++) {
     swapped = false;
     for (var j = 0; j < leaderboard.length-i-1; j++) {
        if (leaderboard[j].attempts > leaderboard[j+1].attempts) {
           var temp = leaderboard[j];
           leaderboard[j] = leaderboard[j + 1];
           leaderboard[j + 1] = temp;
           swapped = true;
        }
     }
     if (swapped == false) {
        break;
     }
   }
   sorted = 2;
}

function sortByTime() {
  var swapped;
  for (var i = 0; i < leaderboard.length - 1; i++) {
     swapped = false;
     for (var j = 0; j < leaderboard.length-i-1; j++) {
        if (leaderboard[j].time > leaderboard[j+1].time) {
           var temp = leaderboard[j];
           leaderboard[j] = leaderboard[j + 1];
           leaderboard[j + 1] = temp;
           swapped = true;
        }
     }
     if (swapped == false) {
        break;
     }
   }
   sorted = 1;
}


function insert_leaderboard(option) {
  var end = new Date();
  var time = (end.getTime() - begin.getTime()) / 1000;
  var date = end.getDate() + "/" + end.getMonth() + "/" + end.getFullYear();
  var entry = new LeaderboardEntry(date, tries, time);
  //Just inserting, not sorted in any order
  if (option === 0 || leaderboard.length === 0) {
    leaderboard.push(entry);
  }
  //Inserting by time
  else if (option === 1) {
    var i = 0;
    console.log(leaderboard.length);
    for (i = 0; i < leaderboard.length; i++) {
      if (leaderboard[i].time > time) {
        leaderboard.splice(i, 0, entry);
        break;
      }
    }
    if (i == leaderboard.length) {
      leaderboard.push(entry);
    }
  }
  //Inserting by attempts
  else {
    var i = 0;
    for (i = 0; i < leaderboard.length; i++) {
      if (leaderboard[i].attempts > tries) {
        leaderboard.splice(i, 0, entry);
        break;
      }
    }
    if (i == leaderboard.length) {
      leaderboard.push(entry);
    }
  }
}

function store_leaderboard() {
  if (loaded) {
  sortByTime();
  localStorage.setItem("length", leaderboard.length);
  for (let i = 0; i < leaderboard.length; i++) {
    localStorage.setItem(i.toString(), JSON.stringify(leaderboard[i]));
  }
}
}
function retrieve_leaderboard() {
  var length = parseInt(localStorage.getItem("length"));
  console.log(length);
  if (isNaN(length)) {
    return;
  }
  for (var i = 0; i < length; i++) {
    var obj = JSON.parse(localStorage.getItem(i.toString()));
    leaderboard.push(new LeaderboardEntry(obj.date, obj.attempts, obj.time));
  }
  sortByTime();
  sorted = 1;
}

function load_leaderboard() {
  $("#leaderboard-data").html("");
  for (let i = 0; i < leaderboard.length && i < 10; i++) {
    var time = leaderboard[i].time;
    var seconds = parseInt(time % 60);
    var minutes = parseInt(time / 60);
    var date = leaderboard[i].date;
    var attempts = leaderboard[i].attempts;
    $("#leaderboard-data").append("<tr><td>Date: " + date + "</td><td>" + attempts + "</td><td>" + minutes + " min " + seconds + " sec</td></tr>");
  }
}

function clearLeaderboard() {
  $("#leaderboard-data").html("");
  localStorage.clear();
  leaderboard = [];
}
