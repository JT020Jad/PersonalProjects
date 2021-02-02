<!DOCTYPE html> <!-- This file uses HTML5 -->
<html lang = "en">
	<?php 
        include 'header.php';
    ?>
        
        <div id = "User-Image"> </div>

        <div class = "UserPanel">
            <section>
                <?php
                    $LibraryDatabase = mysqli_connect('localhost', 'root', '', 'assignmentdb') or die(mysqli_error());
                    $sql = mysqli_query($LibraryDatabase ,"SELECT UserName FROM users WHERE LoggedIn = 1");

                    $QueryResult = $sql;
 
                    while($row = mysqli_fetch_array($QueryResult) )
                    {
                        echo "<h2>";
                        echo "Welcome " . $row['UserName']. "!";
                        echo "</h2>";
                    }
                ?>
            </section>
        </div>

        <div class = "center"> <!-- insert the page content here -->
			<article>
				<img src="Images/book.png" alt="book">
				   	<h2>Search For a Book</h2>
				<a href="search.php" class="more-link">Click Here</a>
			</article>
				
			<article> 
				<img src="images/reserve.jpg" alt="Reserved">
				    <h2>Reserve a Book</h2>
				<a href="reserve.php" class="more-link">Click Here</a>
			</article>
				
			<article> 
				<img src="images/reserved.jpg" alt>
				    <h2>View Reserved Books</h2>
				<a href="viewreserved.php" class="more-link">Click Here</a>
			</article>
		</div>

            
		<div class = "center"> <!-- insert the page content here -->
			<div class = "row">
                <img src  ="Images/logout.png" alt = "logout">
                    <h2>Log Out</h2>
				<a href="logout.php" class="more-link">Click Here</a>
			</div>
		</div>	


        <?php
            include 'footer.php';
        ?>

    </body> <!-- End body -->
</html> <!-- End HTML-->