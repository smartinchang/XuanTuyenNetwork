<!DOCTYPE html>
<?php
 session_start();
 include("connection.inc");
 if(!isset($_GET["obj"]))
  $obj="";
 else
  $obj=$_GET["obj"];
 if(!isset($_GET["act"]))
  $act="";
 else
  $act=$_GET["act"];
 if(!isset($_GET["id"]))
  $id="0";
 else
  $id=$_GET["id"];
?>
<html lang="vn">
 <head>
  <title>XUÂN TUYẾN Network</title>
  <link rel="icon" type="image/png" sizes="32x32" href="images/favicon-32x32.png">
  <?php include("head.inc"); ?>
 </head>
 <body>
  <?php
   include("titlebar.inc");
   include("menubar.inc");
  ?>
  <div class="container-fluid text-muted">
   <?php
    include("content.inc");
   ?>
  </div>
  <?php include("footer.inc"); ?>
 </body>
</html>