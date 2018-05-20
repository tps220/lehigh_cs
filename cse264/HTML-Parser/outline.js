//Name: Thomas Salemy
//HW3: HTML Outline
//Build unordered list only with jquery functions that represents the outline of the html page


//------Global Variables-----//
//A stack of jquery-dom-elements and a stack of their placement in the tree
var stack = new Array();
var stack_location = new Array();
var stack_size = 0;

//Jquery DOM element builder to be appended after function call
var list = $("<tr>");

//Helper variables for recursive, postorder traversal of HTML outline
var previous_level = -1;
var merged = false;



//--------Call Function-------//
$(document).ready(function() {
  //Traverse html document and build list
  $("html").children().each(function(index, item) {
    traverse(item, 0);
  });
  list = list.wrap("<ul></ul>").parent();
  list = list.wrap("<li>html </li>").parent();
  list = list.wrap("<ul></ul>").parent();
  //Append the final result to the body
  $("#parser-title").append(list);
});



//----Postorder Traversal That Builds A JQuery Dom Object of Nested Loops---//
function traverse(node, current_level) {
  //Traverse to each child before looking at its data
  $(node).children().each(function(index, item) {
    traverse(item, current_level + 1);
  });

  //Get relevant information from the node
  var text = $(node).contents().not($(node).children()).text();
  var contents = "";
  var attributes_array = $(node).get(0).attributes;
  $.each(attributes_array, function(index, attribute){
    contents += attribute.name + " (" + attribute.value + ")";
    if (index != attributes_array.length - 1) {
      contents += ",  ";
    }
  });

  //CASE 1: At The First Node Visited
  if (previous_level === -1) {
    //Create jquery dom element for current node
    var element;
    if (text.trim().length) {
      element = $("<li>" + $(node).prop("tagName").toLowerCase() + " " + contents + "<ul> <li>" + "text(" + text + ")" + "</li> </ul> </li>");
    }
    else {
      element = $("<li>" + $(node).prop("tagName").toLowerCase() + " " + contents + "</li>")
    }
    //Push the object and its location onto the respective stack
    stack.push(element);
    stack_location.push(current_level);
    //Update stack size
    stack_size = 1;
  }
  //CASE 2: Neighbor of previous node, on the same tree level
  else if (previous_level === current_level) {
    //Pop the current DOM Object to be appended off the top of the stack
    var current_element = $(stack.pop());
    //Create jquery dom element for current node
    var new_element;
    if (text.trim().length) {
      new_element = $("<li>" + $(node).prop("tagName").toLowerCase() + " " + contents + "<ul> <li>" + "text(" + text + ")" + "</li> </ul> </li>");
    }
    else {
      new_element = $("<li>" + $(node).prop("tagName").toLowerCase() + " " + contents + "</li>")
    }
    //Append the current DOM object in scope and push back on the stack
    current_element.append(new_element);
    stack.push(current_element);
  }
  //CASE 3: Recursed up one level, so create the nested part of the list
  //and append to the neighboring element on the stack if both at the same location
  else if (previous_level > current_level) {
    //Create the nested list by wrapping the children with their parent,
    //and update teh location of the current dom_object in relation to the tree
    var current_element = $(stack.pop());
    var current_parent = stack_location.pop();
    current_element = current_element.wrap("<ul></ul>").parent();
    if (text.trim().length) {
      current_element.prepend("<ul> <li>" + text + "</li> </ul>");
    }
    current_element = current_element.wrap("<li>" + $(node).prop("tagName").toLowerCase() + " " + contents + " </li>").parent();

    //Push the updated Jquery DOM object back onto the stack and apply the update to its location
    stack.push(current_element);
    stack_location.push(current_level);

    //If the Jquery DOM Object has a neighbor on the stack, merge the two elements
    if (stack_size > 1) {
      //Get Parent Element
      var current_parent = stack_location.pop();
      var old_parent = stack_location.pop();
      //If Parents Equal, then combine stacks
      if (current_parent === old_parent) {
        var new_element = $(stack.pop());
        var old_element = $(stack.pop());
        old_element.append(new_element);
        stack.push(old_element);
        stack_location.push(current_level);
        stack_size--;
      }
      //Otherwise, restore the stack of locations to its original state
      else {
        stack_location.push(old_parent);
        stack_location.push(current_parent);
      }
    }

    //If at one of the base nodes, merge the JQuery DOM Object into the bigger
    //JQuery Dom Object builder and clear the current stack, restarting
    //the process for the next base node
    if (current_level === 0) {
      if (merged) {
        list.append(stack.pop());
        stack_location.pop();
      }
      else {
        list = stack.pop();
        stack_location.pop();
        merged = true;
      }
      stack_size--;
      previous_level = -1;
      return;
    }
  }
  //CASE 4: Reached a new sequence of leaf nodes, so restart nested list process
  //with a new JQUERY DOM element and push the new sequence onto the stack
  else {
    var element;
    if (text.trim().length) {
      element = $("<li>" + $(node).prop("tagName").toLowerCase() + " " + contents + "<ul> <li>" + "text(" + text + ")" + "</li> </ul> </li>");
    }
    else {
      element = $("<li>" + $(node).prop("tagName").toLowerCase() + " " + contents + "</li>")
    }
    stack.push(element);
    stack_location.push(current_level);
    stack_size++;
  }
  //Update previous and current level
  previous_level = current_level;
}
