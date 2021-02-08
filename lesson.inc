<?php
 $lesson_query=$conn->query("select `id`,`title`,`subject`,`content`,`position` from `lesson` where `id`=".$id) or die(mysql_error());
 $lesson=$lesson_query->fetch_assoc();
 $subject_query=$conn->query("select `id`,`title` from `subject` where `id`=".$lesson["subject"]) or die(mysql_error());
 $subject=$subject_query->fetch_assoc();
?>
<div class="row">
 <div class="col-sm-2">
  <h5><?php echo $subject["title"]; ?></h5>
  <ul class="list-group">
   <?php
    $lesson_list_query=$conn->query("select `id`,`title`,`position` from `lesson` where `subject`=".$subject["id"]." and `status`=1") or die(mysql_error());
	while ($lesson_list=$lesson_list_query->fetch_assoc())
	{
	 if ($id==$lesson_list["id"])
	  echo "<li class=\"list-group-item active small\"><a href=\"index.php?obj=lesson&id=".$lesson_list["id"]."\"><font color=\"white\">".$lesson_list["title"]."</font></a></li>";
	 else
	  echo "<li class=\"list-group-item small\"><a href=\"index.php?obj=lesson&id=".$lesson_list["id"]."\">".$lesson_list["title"]."</a></li>";
	}
   ?>
  </ul>
 </div>
 <div class="col-sm-7">
  <?php
   echo "<h3>".$lesson["title"]."</h3><br>";
   echo $lesson["content"];
  ?>
  <div class="row">&nbsp;</div>
  <div class="row">
   <div class="col-sm-6">
    <?php
	 $lesson_more_query=$conn->query("select `id` from `lesson` where `status`=1 and `subject`=".$lesson["subject"]." and `position`<".$lesson["position"]." order by `position` desc limit 0,1") or die(mysql_error());
	 $lesson_more_amount=$lesson_more_query->num_rows;
	 if ($lesson_more_amount>0)
	  {
	   $lesson_more=$lesson_more_query->fetch_assoc();
	   echo "<p><a href=index.php?obj=lesson&id=".$lesson_more["id"]."><i class=\"fas fa-angle-double-left\"></i> Bài trước</a></p>";
	  }
	?>
   </div>
   <div class="col-sm-6">
    <?php
	 $lesson_more_query=$conn->query("select `id` from `lesson` where `status`=1 and `subject`=".$lesson["subject"]." and `position`>".$lesson["position"]." order by `position` limit 0,1") or die(mysql_error());
	 $lesson_more_amount=$lesson_more_query->num_rows;
	 if ($lesson_more_amount>0)
	  {
	   $lesson_more=$lesson_more_query->fetch_assoc();
	   echo "<p align=\"right\"><a href=index.php?obj=lesson&id=".$lesson_more["id"].">Bài sau <i class=\"fas fa-angle-double-right\"></i></a></p>";
	  }
	?>
   </div>
  </div>
 </div>
 <div class="col-sm-3"><?php include("ad_right.inc"); ?></div>
</div>