//Globals
var HOST = "localhost:3000";
var SERVER = "http://" + HOST + "/";
var userID = -1;
var username;
var letters = new Array();
var col_length;

//Represent letter in table locally
class Letter {
  constructor(row, column) {
    this.row = row;
    this.column = column;
    this.toggle = 0;
    this.claimed = 0;
  }
}


//Toggle letter when clicked on
function toggleLetter(element) {
  //Get and Format Input
  var info = element.id;
  var row = parseInt(element.id);
  var column = 0;
  var multiplier = 1;
  for (let i = info.length - 1; i > 0; i--) {
    if (info[i] == ' ') {
      break;
    }
    column += multiplier * (info[i] - '0');
    multiplier *= 10;
  }
  //Change the user interface if not a claimed word
  if (letters[row * col_length + column].claimed == 0) {
    if (letters[row * col_length + column].toggle == 0) {
      $(element).css({"background-color" : "#6F9FD8", "color" : "white"});
    }
    else {
      $(element).css({"background-color" : "white", "color" : "black"});
    }
  }
  else {
    if (letters[row * col_length + column].toggle == 0) {
      $(element).css({"background-color" : "#6F9FD8", "color" : "white"});
    }
    else {
      $(element).css({"background-color" : "red", "color" : "white"});
    }
  }
  //Store current toggle state
  letters[row * col_length + column].toggle ^= 1;
}

//Load game board
function load_game_board() {
  $.ajax(
    {
            method: "GET",
            url: "wordsearch/puzzle",
            data: {id : userID},
            dataType: "json",
            success: function (result) {
              var theme = result.theme;
              var rows = result.nrows;
              var cols = result.ncols;
              col_length = cols;
              var grid = result.grid;
              var appender = "<div id=\"game-container\"> <h1 class=\"game-board-title\"> Game Board </h1>"
                            + "<h1 id=\"game-board-title-info\">" + theme + "</h1>"
                            + "<table id=\"game-board\">";
              for (let i = 0; i < rows; i++) {
                appender += "<tr>"
                for (let j = 0; j < cols; j++) {
                  letters.push(new Letter(i, j))
                  let name = i.toString() + " " + j.toString();
                  appender += "<td id=\"" + name + "\"class=\"letters\" onclick=\"toggleLetter(this)\">" + grid[i * cols + j] + "</td>";
                }
                appender += "</tr>"
              }
              appender += "</table><button type=\"button\" id=\"submit-word\" onclick=\"processSubmit()\">Submit Word</button></div>"
              + "<div id=\"leaderboard-container\"><h1 class=\"game-board-title\"> Leaderboard </h1><table id=\"score-table\"></table></div>";
              $("#container").append(appender);
            },
            error: function (jqXHR, textStatus, errorThrown) {
                alert("Error: " + jqXHR.responseText);
                alert("Error: " + textStatus);
                alert("Error: " + errorThrown);
            }
      }
    );
}

//Process a user word submission
function processSubmit() {
  //Get the toggled letters on the board
  //and format for communication with server
  var set_letters = new Array();
  for (let i = 0; i < letters.length; i++) {
    if (letters[i].toggle == 1) {
      set_letters.push({
        r : letters[i].row,
        c : letters[i].column
      });
    }
  }
  var body = $("body");
  $.ajax(
    {
            method: "GET",
            url: "wordsearch/submit",
            data: {id : userID,
                  letters: set_letters},
            dataType: "json",
            success: function (result) {
              if (result.success) {
                for (var i = 0; i < set_letters.length; i++) {
                  var row = set_letters[i].r;
                  var col = set_letters[i].c;
                  letters[row * col_length + col].claimed = 1;
                  letters[row * col_length + col].toggle= 0;
                  var letter_id = row.toString() + " " + col.toString();
                  body.find('td[id="'+letter_id+'"]').css("background-color", "red");
                }
              }
            },
            error: function (jqXHR, textStatus, errorThrown) {
                alert("Error: " + jqXHR.responseText);
                alert("Error: " + textStatus);
                alert("Error: " + errorThrown);
            }
      }
    );
}


function attachEventHandlers() {
    $(document).on("click", "#username-submit",  function () {
        login($("#username-input").val(), $(this).parent());
    });
}

//Process login properly, making sure to account for asynchronous environemnt
//so that we block until server responds to request and userID can be
//changed or not changed before it's value is accessed and checked after
function login(userid, obj) {
    $.ajax(
      {
              method: "GET",
              url: "wordsearch/login",
              data: {username : userid},
              async: false,
              dataType: "json",
              success: function (result) {
                if (result.success) {
                  userID = result.id;
                  username = result.username;
                }
              },
              error: function (jqXHR, textStatus, errorThrown) {
                  alert("Invalid Username, Try Again");
              }
        }
      );
  //Running synchronously,
  //therefore after ajax call completed,
  //if sucessful and USERID has changed then
  //remove the login_screen and display the board
  if (userID != -1) {
    obj.children().first().next().remove();
    obj.children().first().next().remove();
    obj.children().first().next().remove();
    obj.children().first().next().remove();
    obj.children().first().next().remove();
    load_game_board(userID);
  }
}

//Helper function to sort players on leaderboard, O(n^2) complexity
//is okay since only dealing with less than 40 players
function sort(players) {
  for (let i = 0; i < players.length - 1; i++) {
    let swapped = 0;
    for (let j = 0; j < players.length - 1 - i; j++) {
      if (players[j].score < players[j + 1].score) {
        var temp = players[j];
        players[j] = players[j + 1];
        players[j + 1] = temp;
        swapped = 1;
      }
    }
    if (swapped == 0) {
      return;
    }
  }
}

//Load leaderboard from server socket
function loadLeaderboard(players) {
  //sort players based upon score
  sort(players);
  //Update leaderboard by replacing inner html
  var appender = "<tr><th id=\"row-header-1\">Player Name</th><th id=\"row-header-2\">Score</th></tr>"
  for (let i = 0; i < players.length; i++) {
      //If winner, background color becomes yellow, otherwise normal output
      if (players[i].winner) {
        appender += "<tr><td class =\"player-winner\">" + players[i].name + "</td><td class =\"player-winner\">" + players[i].score + "</td></tr>";
      }
      else {
      appender += "<tr><td class =\"player-data\">" + players[i].name + "</td><td class =\"player-data\">" + players[i].score + "</td></tr>";
      }
  }
  $("#score-table").html(appender);
}

//Helper function to toggle the claimed words to their proper configurations
function claimWord(row, col) {
  if (userID != -1) {
    letters[row * col_length + col].claimed = 1;
    var letter_id = row.toString() + " " + col.toString();
    if (letters[row * col_length + col].toggle == 0) {
      $("body").find('td[id="'+letter_id+'"]').css({"background-color" : "red", "color" : "white"});
    }
  }
}

//Load the claimed words from the socket and update local game accordingly
function loadWords(new_word_data) {
  var list = new_word_data.words;
  for (let i = 0; i < list.length; i++) {
    var chars = list[i].letters;
    for (let j = 0; j < chars.length; j++) {
      claimWord(parseInt(chars[j].r), parseInt(chars[j].c));
    }
  }
}

//Onload function that begins the proper series of events
$( () => {
    attachEventHandlers();
    var socket = io.connect(HOST);

    // Update leaderboard
    socket.on('players', function (players) {
        loadLeaderboard(players);
    });

    socket.on('gridupdates', function (new_word_data) {
        loadWords(new_word_data);
    });
});
