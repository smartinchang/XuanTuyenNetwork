<nav class="navbar navbar-expand-sm bg-dark navbar-dark">
 <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="index.php?obj=collapsibleNavbar"><span class="navbar-toggler-icon"></span></button>
  <div class="collapse navbar-collapse" id="collapsibleNavbar">
   <ul class="navbar-nav">
	<li class="nav-item"><a class="nav-link active" href="index.php">Trang chủ</a></li>
	<li class="nav-item dropdown">
	 <a class="nav-link dropdown-toggle" href="#" id="navbardrop" data-toggle="dropdown">Các chương trình đào tạo</a>
	 <div class="dropdown-menu">
	  <?php
	   $subject_query=$conn->query("select `id`,`title` from `subject` where `status`=1 order by `position`") or die(mysql_error());
	   while ($subject=$subject_query->fetch_assoc())
	    echo "<a class=\"dropdown-item\" href=\"index.php?obj=subject&id=".$subject["id"]."\">".$subject["title"]."</a>";
	  ?>
	 </div>
	</li>
	<li class="nav-item dropdown">
	 <a class="nav-link dropdown-toggle" href="#" id="navbardrop" data-toggle="dropdown">Blog</a>
	 <div class="dropdown-menu">
	  <?php
	   $category_query=$conn->query("select `id`,`title` from `category` where `status`=1 order by `position`") or die(mysql_error());
	   while ($category=$category_query->fetch_assoc())
	    echo "<a class=\"dropdown-item\" href=\"index.php?obj=category&id=".$category["id"]."\">".$category["title"]."</a>";
	  ?>
	 </div>
	</li>
  </ul>
  </div>
 </nav>
<br>