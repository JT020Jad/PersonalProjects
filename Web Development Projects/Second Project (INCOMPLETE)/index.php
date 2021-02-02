<!DOCTYPE html> <!-- This file uses HTML5 -->
<html lang = "en">
	<?php 
		include 'header.php';
		include 'loginreset.php';
    ?>

        <div id = "banner-image">
			<br> <br> <br>
            <h1> 
                <a class = "button" href = "login.php" style = "vertical-align: middle">
                    <span> Log In </span>
                </a>
			</h1>
		</div>

        <main><!-- This is  the main content -->
			<div class = "center"><!-- insert the page content here -->
				<article>
					<img src="images/padlock.png" alt="Padlock">
				   		<h2>Log In</h2>
						<p>Go To the Login Page</p>
						<a href="login.php" class="more-link">Click Here</a>
				</article>
				
				<article> 
					<img src="images/register.jfif" alt="Regster">
				    <h2>Registration</h2>
					<p>Register if you do not already have an account</p>
					<a href="register.php" class="more-link">Click Here</a>
				</article>
				
				<article> 
					<img src="images/customer.png" alt>
				    <h2>Contact Info</h2>
					<p>Info on how to contact me.</p>
					<a href="contact.php" class="more-link">Click Here</a>
				</article>
			</div>
			
            
			<div class = "center"><!-- insert the page content here -->
				<div class = "row">
                    <img src  ="Images/codem.png" alt = "Image of a computer">
					<p>Find out more about me </p>
					<a href="who.php" class="more-link">Click Here</a>
				</div>
			</div>	
        </main>


        <?php
            include 'footer.php';
        ?>

    </body> <!-- End body -->
</html> <!-- End HTML-->