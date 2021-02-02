<!DOCTYPE html> <!-- This file uses HTML5 -->
<html lang = "en">
    <?php 
        include 'header.php';
        include_once 'loginreset.php';
    ?>
            
        <div id = "Registration-Image"> </div>
        
        <br><br>

        <div>
            <h2>Library Sign Up</h2>
                <form action = "registrationcheck.php" method = "post">
                    <p> <input type = "text" name = "Username" placeholder = "Username" required> </p>

                    <p> <input type = "password" name = "Password" placeholder = "Password" required> </p>

                    <p> <input type = "text" name = "FirstName" placeholder = "First Name" required> </p>

                    <p> <input type = "text" name = "Surname" placeholder = "Surname" required> </p>

                    <p> <input type = "text" name = "Address1" placeholder = "Address line 1" required> </p>

                    <p> <input type = "text" name = "Address2" placeholder = "Address line 2 (optional)"> </p>

                    <p> <input type = "text" name = "City" placeholder = "City" required> </p>

                    <p> <input type = "text" name = "Landline" placeholder = "Landline (optional)"> </p>

                    <p> <input type = "text" name = "Mobile" placeholder = "Mobile" required> </p>

                    <br>

                    <p> <input type = "submit" placeholder = "Sign Up"> </p>
                </form>
        </div>

        <br>

        <?php
            include 'footer.php';
        ?>

    </body>
</html>