<?php
 $topic_query=$conn->query("select `title`,`abstract`,`content`,`category`,`position` from `topic` where `id`=".$id) or die(mysql_error());
 $topic=$topic_query->fetch_assoc();
?>
<h2><?php echo $topic["title"]; ?></h2>
<div class="row">
 <div class="col-sm-9">
  <?php
   echo $topic["abstract"];
   echo $topic["content"];
  ?>
  <br><br><h2><font style="font-family:'Dancing Script',cursive;color:orange"><u>&nbsp;&nbsp;Các bài viết cùng chủ đề:&nbsp;&nbsp;</u></font></h2>
  <div class="row">
   <?php
    $topic_more_query=$conn->query("select * from `topic` where `status`=1 and `category`=".$topic["category"]." and  `position`<".$topic["position"]." order by `position` desc limit 0,9") or die(mysql_error());
    while ($topic_more=$topic_more_query->fetch_assoc())
    {
     echo "<div class=\"col-sm-4\">";
     echo "<img class=\"img-fluid\" src=\"".$topic_more["picture"]."\" alt=\"".$topic_more["title"]."\">";
     echo "<a href=\"index.php?obj=topic&id=".$topic_more["id"]."\">";
     echo "<h4>".$topic_more["title"]."</h4>";echo "<p>".$topic_more["abstract"]."</p>";
     echo "</a>";
     echo "</div>";
    }
   ?>
  </div>
 </div>
 <div class="col-sm-3"><?php include("ad_right.inc"); ?></div>
</div>