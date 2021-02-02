<!DOCTYPE html> <!-- This file uses HTML5 -->
<html lang = "en">
    <?php 
        include 'header.php';
    ?>


    <?php 
        $LibraryDatabase =  mysqli_connect('localhost', 'root', '', 'assignmentdb') or die(mysqli_error() );
        echo '<table border = "1">' . "<br>";

        $QueryResult = mysqli_query($LibraryDatabase, "SELECT UserName From Users WHERE LoggedIn = 1");
        $ViewReserved = mysqli_query($LibraryDatabase, "SELECT * FROM reserved_books WHERE UserPass = $QueryResult");

        if($ViewReserved ->num_rows > 0)
                    {
                        echo "<tr>
                                <th>ISBN</th>
                                <th>Book Title</th>
                                <th>Author</th>
                                <th>Edition</th>
                                <th>Year</th>
                                <th>CategoryID</th>
                            </tr>";

                        while($row = $ViewReserved ->fetch_assoc() )
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

                            echo ("</td></tr>");
                        } // end while

                        mysqli_close($LibraryDatabase);
                    } // end if

    ?>
       
        
    <?php
        include 'footer.php';
    ?>

    </body> <!-- End body -->
</html> <!-- End HTML-->