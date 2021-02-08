<div class="row">
 <div class="col-sm-12"><h2><font style="font-family:'Dancing Script',cursive;color:orange"><u>&nbsp;&nbsp;Blog&nbsp;&nbsp;</u></font></h2></div>
</div>
<div class="row">
<?php
 $topic_query=$conn->query("select * from `topic` where `status`=1 order by `id` desc limit 0,12") or die(mysql_error());
 while ($topic=$topic_query->fetch_assoc())
 {
  echo "<div class=\"col-sm-3\">";
  echo "<img class=\"img-fluid\" src=\"".$topic["picture"]."\" alt=\"".$topic["title"]."\">";
  echo "<a href=\"index.php?obj=topic&id=".$topic["id"]."\">";
  echo "<h4>".$topic["title"]."</h4>";
  echo "<p>".$topic["abstract"]."</p>";
  echo "</a>";
  echo "</div>";
 }
?>
</div>