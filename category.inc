<?php
 $category_query=$conn->query("select `title` from `category` where `id`=".$id." order by `position`") or die(mysql_error());
 $category=$category_query->fetch_assoc();
?>
<h1><font style="font-family:Dancing Script,cursive;"><?php echo $category["title"]; ?></font></h1>
<div class="row">
 <div class="col-sm-9">
  <?php
   $topic_query=$conn->query("select `id`,`title`,`abstract`,`picture` from `topic` where `category`=".$id." and `status`=1 order by `position` desc limit 0,10") or die(mysql_error());
   while ($topic=$topic_query->fetch_assoc())
   {
    echo "<div class=\"row\">";
	echo "<div class=\"col-sm-4\">";
	echo "<a href=\"index.php?obj=topic&id=".$topic["id"]."\">";
	echo "<img class=\"img-fluid\" src=\"".$topic["picture"]."\" alt=\"".$topic["title"]."\">";
	echo "</a>";
	echo "</div>";
    echo "<div class=\"col-sm-8\">";
	echo "<a href=\"index.php?obj=topic&id=".$topic["id"]."\">";
	echo "<h5>".$topic["title"]."</h5>";
	echo $topic["abstract"];
	echo "</a>";
	echo "</div>";
	echo "</div>";
   }
  ?>
 </div>
 <div class="col-sm-3"><?php include("ad_right.inc"); ?></div>
</div>