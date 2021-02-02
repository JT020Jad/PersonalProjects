<!DOCTYPE html> <!-- This file uses HTML5 -->
<html lang = "en">
    <?php 
        include 'header.php';
    ?>
        
        <div class = "SearchResult">
            <?php
                $LibraryDatabase = mysqli_connect('localhost', 'root', '', 'assignmentdb') or die(mysqli_error() );
                echo '<table border = "1">' . "<br>";

                if (isset($_POST['ISBN'] ) && isset($_POST['BookTitle'] ) && isset($_POST['Author'] ) && isset($_POST['Edition'] ) && isset($_POST['Year'] ) && isset($_POST['CategoryID'] ) )
                {
                    $ISBN = mysqli_real_escape_string($LibraryDatabase, $_POST['ISBN'] );
                    $BookTitle = mysqli_real_escape_string($LibraryDatabase, $_POST['BookTitle'] );
                    $Author = mysqli_real_escape_string($LibraryDatabase, $_POST['Author'] );
                    $Edition = mysqli_real_escape_string($LibraryDatabase, $_POST['Edition'] );
                    $Year = mysqli_real_escape_string($LibraryDatabase, $_POST['Year'] );
                    $CategoryID = mysqli_real_escape_string($LibraryDatabase, $_POST['CategoryID'] );
                    

                    $QueryResult = mysqli_query($LibraryDatabase, "SELECT * FROM books WHERE ISBN = '" . $_POST["ISBN"] . "' or BookTitle = '". $_POST["BookTitle"]."' or Author = '". $_POST["Author"]."' or Edition = '". $_POST["Edition"]."' or Year = '". $_POST["Year"]."'or CategoryID = 00 + '". $_POST["CategoryID"]."' or Reserved ");

                    
                    if($QueryResult ->num_rows > 0)
                    {
                        echo "<tr>
                                <th>ISBN</th>
                                <th>Book Title</th>
                                <th>Author</th>
                                <th>Edition</th>
                                <th>Year</th>
                                <th>CategoryID</th>
                                <th>Reserved</th>
                            </tr>";

                        while($row = $QueryResult ->fetch_assoc() )
                        {
                            echo "<tr> <td>";
                            echo (htmlentities($row["ISBN"]) );

                            echo ("</td><td>");
                            echo (htmlentities($row["BookTitle"]) );

                            echo ("</td><td>");
                            echo (htmlentities($row["Author"]) );

                            echo ("</td><td>");
                            echo (htmlentities($row["Edition"]) );

                            echo ("</td><td>");
                            echo (htmlentities($row["Year"]) );

                            echo ("</td><td>");
                            echo (htmlentities($row["CategoryID"]) );

                            echo ("</td><td>");
                            echo (htmlentities($row["Reserved"]) );

                            echo ("</td></tr>");
                        } // end while

                        mysqli_close($LibraryDatabase);
                    } // end inner if
                    
                    echo '<a href = "search.php"> Return to Search </a> <br>';
                    echo '<a href = "reserve.php"> Reserve a Book </a>';
                    return;
                }//End outer if
            ?>
        </div>
    
        
        <div class = "SearchInput">
            <br> <Br> <br>
            <h3>Enter Any:</h3>
            
            <form method = "post">
                <p> 
                    ISBN: <input type = "text" name= "ISBN"> 
                </p>

                <p> 
                    Book Title: <input type = "text" name = "BookTitle"> 
                </p>
                
                <p> 
                    Author: <input type = "text" name = "Author"> 
                </p>

                <p> 
                    Edition: <input type = "text" name = "Edition"> 
                </p>

                <p> 
                    Year: <input type = "text" name = "Year"> 
                </p>

                <p> 
                    CategoryID: <input type = "text" name = "CategoryID"> 
                </p>


                <p> 
                    <br> <br>
                    <input type  = "Submit" value = "Confirm">
                </p>
            </form>


            <div id = "CancelButton">
                <form action = "interface.php">
                    <input type = "Submit" value = "Cancel" />
                </form> 
            </div>
        </div>
        

        <?php
            include 'footer.php';
        ?>

    </body> <!-- End body -->
</html> <!-- End HTML-->