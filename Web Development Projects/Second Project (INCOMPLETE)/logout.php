<!DOCTYPE html> <!-- This file uses HTML5 -->
<html lang = "en">
    <?php 
        include 'header.php';
    ?>
    
        <div id = "logout-image">

            <!-- Spacers -->
            <br> <br> <br><br> <br> <br><br> 
            <br> <br><br> <br> <br><br> <br> 
            <br> <br> <br><br> <br> <br><br> 
            <!-- End Spacers -->

            <h1> 
                <a class = "button" href = "index.php" style = "vertical-align: middle">
                    <span> Home </span>
                </a>
			</h1>
		</div>

        <!-- Spacers -->
        <br> <br><br> <br><br> <br> <br>
        <!-- Spacers -->

        
        <div class = UserPanel>
            <?php
                $message = "";

                $LibraryDatabase = mysqli_connect('localhost', 'root', '', 'assignmentdb') or die(mysqli_error());
                $QueryResult = mysqli_query($LibraryDatabase ,"SELECT * FROM users WHERE LoggedIn != 0");

                mysqli_query($LibraryDatabase, "UPDATE users SET LoggedIn = 0");

                
                $message = "<h3>You have been successfully logged out!</h3>";
                echo $message;
            ?>
        </div>


        <?php
            include 'footer.php';
        ?>

    </body> <!-- End body -->
</html> <!-- End HTML-->