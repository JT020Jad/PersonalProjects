<!DOCTYPE html> <!-- This file uses HTML5 -->
<html lang = "en">
	<?php 
        include 'header.php';
    ?>

			<div id ="map">
				<iframe src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d2382.3414580735366!2d-6.270425284193393!3d53.337143579977145!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x48670c2089d84a1d%3A0x6e1d03e3d62489ae!2sTU%20Dublin%20Kevin%20Street!5e0!3m2!1sen!2sie!4v1576104039447!5m2!1sen!2sie" width="1520" height="450" frameborder="0" style="border:0;" allowfullscreen=""> </iframe>
			</div>
		
		
		<main><!-- This is  the main content -->
		<hr><br>
			<h3 id = "contact">Contact Information</h3>
			
			<section><!-- insert the page content here -->
				<div class="row">
					<div class="column">
						<h2>Leave Message</h2>
					    <form method="post" action= "index.php">
						<p><label>Full Name:</label>
						<input type="text" name="name"></p>
				
						<p><label>Email Address: </label>
						<input type="email" name="email"></p>
					   
						<p><label>Leave a Message </label>
						<textarea type  =" textarea" name="message" rows="4" cols="20" ></textarea></p>
							
						<input type="submit" value="Submit">
					</form> 

					</div>
					
					<div class="column">
						<h2>Visit Us</h2>
						
						<address>
							<p>TU Dublin City Campus</p>
							<p>Kevin Street Lower</p>
							<p>Dublin 2</p>
						</address>
					</div>	
				</div>
			</section>
        </main>
        

        <?php
            include 'footer.php';
        ?>
		
	</body>
</html>
