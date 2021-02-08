<?php
 $lesson_query=$conn->query("select `id`,`title` from `lesson` where `subject`=".$id." and `status`=1 order by `position` limit 0,1") or die(mysql_error());
 $lesson=$lesson_query->fetch_assoc();
 header("location:index.php?obj=lesson&id=".$lesson["id"]);
?>