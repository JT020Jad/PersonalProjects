<!DOCTYPE html> <!-- This file uses HTML5 -->
<html lang = "en">
    <?php 
        include 'header.php';
    ?>
        
        <div class = "Reservation">
            <?php
                $ErrorMessage = "";

                $LibraryDatabase = mysqli_connect('localhost', 'root', '', 'assignmentdb') or die(mysqli_error() );
                $User = mysqli_query($LibraryDatabase, "SELECT UserName FROM users WHERE LoggedIn != 0" );

                $ReservedCheck = mysqli_query($LibraryDatabase, "SELECT * FROM books WHERE Reserved = 'Y' ");


                if(isset($_POST['ISBN'] ) && $ReservedCheck != 'Y')
                {
                    $ISBN = $_POST['ISBN'];
                    $Reserve = "UPDATE books SET Reserved = 'Y' WHERE ISBN = '$ISBN' ";

                    $Date = date("Y-m-d");
                    $Reserved = mysqli_query($LibraryDatabase, "INSERT INTO reserved books VALUES ('$ISBN', '$User', '$Date') ");

                    mysqli_query($LibraryDatabase, $Reserve);
                    mysqli_query($LibraryDatabase, $Reserved);
                }

                else
                {
                    $ErrorMessage = "Error! Check ISBN or Check Book Reservation Status";
                    echo $ErrorMessage;
                }
            ?>
        </div>
        

        <div class = "SearchInput">
            <br> <br> <br>
            <h3>Book Reservation Portal: </h3>
            
            <form method = "post">
                <p> 
                    ISBN: <input type = "text" name= "ISBN" placeholder = "ISBN" required> 
                </p>

                <p> 
                    <br> <br>
                    <input type  = "Submit" value = "Confirm">
                </p>
            </form>
        </div>

        <div id = "CancelButton">
            <form action = "interface.php">
                <input type = "Submit" value = "Cancel" />
            </form> 
        </div>
       
        <br> <br><br> <br><br> <br><br>
        <?php
            include 'footer.php';
        ?>

    </body> <!-- End body -->
</html> <!-- End HTML-->