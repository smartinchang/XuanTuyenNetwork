<?php
 $advertisement_query=$conn->query("select `content` from `advertisement` where `area`=2 and `status`=1") or die(mysql_error());
 while ($advertisement=$advertisement_query->fetch_assoc())
  echo $advertisement["content"]."<br><br>";
?>