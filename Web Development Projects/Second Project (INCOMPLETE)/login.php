<!DOCTYPE html> <!-- This file uses HTML5 -->
<html lang = "en">
    <?php
        include 'header.php';
        include 'loginreset.php';
    ?>

        <div id = "Registration-Image"> </div>
        
        <div>
            <form action = "CredentialsCheck.php" method = "post">
                  <label>
                        <h3> Username: </h3>
                  </label>

                   <input type = "text" name = "username" placeholder = "Username" required>
                   <br>


                   <label>
                        <h3> Password: </h3>
                   </label>

                   <input type = "password" name = "password" placeholder = "Password" autocomplete = "off" required>
                       <br><br>

                    <input type = "submit" value = "Login">


                    <br> <br> <br> <br>
                        <p> 
                            No account? <br>
                            <a href = "register.php"> Register Here </a>
                        </p>
            </form>
        </div>

        <br> 

        <?php
            include 'footer.php';
        ?>
        
    </body> <!-- End body -->
</html> <!-- End HTML-->