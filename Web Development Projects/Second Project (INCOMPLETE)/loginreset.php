<?php
    $LibraryDatabase = mysqli_connect('localhost', 'root', '', 'assignmentdb') or die(mysqli_error() );

    $QueryResult = "UPDATE users SET LoggedIn = 0 WHERE LoggedIn != 0";
    mysqli_query($LibraryDatabase, $QueryResult);
    
    mysqli_close($LibraryDatabase);
?>