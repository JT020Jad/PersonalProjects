<!DOCTYPE html> <!-- This file uses HTML5 -->
<html lang = "en">
    <?php 
        include 'header.php';
    ?>


        <div id = "Registration-Image"> </div>


        <!-- Establish Connection to Database -->
        <div class = "message">
            <?php
                $message = "";
                
                if(count($_POST) > 0) 
                {
                    $LibraryDatabase = mysqli_connect('localhost', 'root', '', 'assignmentdb') or die(mysqli_error());
                    $QueryResult = mysqli_query($LibraryDatabase ,"SELECT * FROM users WHERE UserName = '" . $_POST["username"] . "' and UserPass = '". $_POST["password"]."'");

                    $Counter  = mysqli_num_rows($QueryResult);
                    if($Counter == 0) 
                    {
                        $message = "Invalid Username or Password!";
                        echo $message, "<br><br>";
                        
                        
                        echo "<br><a href = 'login.php' class = 'more-link'> Try Again </a>";
                    } // End inner if

                    else 
                    {
                        mysqli_query($LibraryDatabase, "UPDATE users SET LoggedIn = 1 WHERE UserName = '" . $_POST["username"] . "' and UserPass = '". $_POST["password"]."' ");
                        $message = "You are now logged in!";
                        echo $message, "<br><br>";


                        echo "<a href = 'interface.php' class = 'more-link'> Continue </a>";
                        mysqli_close($LibraryDatabase);
                    } // End else
                } // End outer if
            ?>
        </div>
    

        <!-- Spacers -->
        <br> <br>
        <!-- End of Spacers -->



        <?php
            include 'footer.php';
        ?>

    </body> <!-- End body -->
</html> <!-- End HTML-->