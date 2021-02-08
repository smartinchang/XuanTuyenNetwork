<div class="row">
 <div class="col-sm-12"><h2><font style="font-family:'Dancing Script',cursive;color:orange"><u>&nbsp;&nbsp;Các chương trình đào tạo&nbsp;&nbsp;</u></font></h2></div>
</div>
<div class="row">
<?php
 $subject_query=$conn->query("select * from `subject` where `status`=1 order by `position`") or die(mysql_error());
 while ($subject=$subject_query->fetch_assoc())
 {
  echo "<div class=\"col-sm-4\">";
  echo "<center>";
  echo "<img class=\"img-fluid\" src=\"".$subject["picture"]."\" alt=\"".$subject["title"]."\">";
  echo "<a href=\"index.php?obj=subject&id=".$subject["id"]."\">";
  echo "<h4>".$subject["title"]."</h4>";
  echo "</a>";
  echo "</center>";
  echo "</div>";
 }
?>
</div>