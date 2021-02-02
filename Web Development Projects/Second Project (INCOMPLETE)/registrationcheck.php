<!DOCTYPE html> <!-- This file uses HTML5 -->
<html lang = "en">
    <?php 
        include 'header.php';
    ?>
            
            <div id = "Registration-Image"> </div>

            <div class = "message">    
                <?php
                    $LibraryDatabase = mysqli_connect('localhost', 'root', '', 'assignmentdb') or die(mysqli_error());
                    $QueryResult =  mysqli_query($LibraryDatabase, "SELECT * FROM users");

                    
                    if(isset($_POST['Username'] ) && isset($_POST['Password'] ) && isset($_POST['FirstName'] ) && isset($_POST['Surname'] ) && isset($_POST['Address1'] ) && isset($_POST['Address2'] ) && isset($_POST['City'] ) && isset($_POST['Landline'] ) && isset($_POST['Mobile'] ) )
                    {

                        $Username = mysqli_real_escape_string($LibraryDatabase, $_POST['Username'] );

                        $Password = mysqli_real_escape_string($LibraryDatabase, $_POST['Password'] );

                        $FirstName = mysqli_real_escape_string($LibraryDatabase, $_POST['FirstName'] );

                        $Surname = mysqli_real_escape_string($LibraryDatabase, $_POST['Surname'] );

                        $Address1 = mysqli_real_escape_string($LibraryDatabase, $_POST['Address1'] );

                        $Address2 = mysqli_real_escape_string($LibraryDatabase, $_POST['Address2'] );

                        $City = mysqli_real_escape_string($LibraryDatabase, $_POST['City'] );

                        $Landline = mysqli_real_escape_string($LibraryDatabase, $_POST['Landline'] );

                        $Mobile = mysqli_real_escape_string($LibraryDatabase, $_POST['Mobile'] );

                        $QueryResult = "INSERT INTO users (UserName, UserPass, FirstName, Surname, AddressLine1, AddressLine2, City, Landline, Mobile, LoggedIn) VALUES ('$Username', '$Password', '$FirstName', '$Surname', '$Address1', '$Address2', '$City', '$Landline', '$Mobile', 0 )";


                        mysqli_query($LibraryDatabase, $QueryResult);
                        echo "Registration Successful <br><br> <a href = 'login.php' class = 'more-link'> Continue </a>";

                        mysqli_close($LibraryDatabase);
                    }//End if
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