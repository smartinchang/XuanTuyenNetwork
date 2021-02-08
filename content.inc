<?php
 switch($obj)
 {
  case "":
   include("home.inc");
  break;
  case "category":
   include("category.inc");
  break;
  case "topic":
   include("topic.inc");
  break;
  case "subject":
   include("subject.inc");
  break;
  case "lesson":
   include("lesson.inc");
  break;
 }
?>