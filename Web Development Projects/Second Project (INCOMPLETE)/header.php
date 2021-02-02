    <head>
        <title> DT228 Book Reservation </title>
        <meta charset = "UTF-8">

        <link rel = "stylesheet" href = "Stylesheet/style.css" /> <!-- External Stylesheet -->
        <script src = "JavaScript/main.js"> </script> <!-- JavaScript External Source File -->
        <script>
            function start()
                {
                    browserDetection();
                    hitCount();
                } // End JavaScript Function
        </script> <!-- End JavaScript Function Call -->
    </head>


    <body onload = "start()"> <!-- Start of the Webpage -->

        <!-- **Header Section** -->
        <header><!-- This is the Header bar-->
            <h1 id = "text" onmouseover = "mouseOver()" onmouseout = "mouseOut()"> 
            <a href = "index.php"> DT228 Library </a> </h1>
            <hr> <hr>
            

		    <nav><!-- This is the Navigation bar-->
				<ul>
					<li><a href = "index.php"> Home </a></li>
					<li><a href = "login.php"> Log In </a></li>
					<li><a href = "register.php"> Register </a></li>
					<li><a href = "who.php"> About Me </a></li>
				</ul>
			</nav>
        </header>
