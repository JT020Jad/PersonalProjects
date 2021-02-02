/*
1.Browser plug-in detection
2.Status bar messages
3.Scrolling status bars
4.Rollovers
5.Cycling animations
6.Slide shows
7.Dynamic frames
8.Form verification
9.New windows,
10.Cookies 
11.Dynamic webpage updates
12.Hit Page Counter
*/


/*
*******************************************************************
Script 1: Browser Plugin Detection (browserdetection.html)
this function detects the user browser
******************************************************************
*/
function browserDetection()
 { 
	if(navigator.userAgent.indexOf("Chrome") != -1 )
	{
		document.getElementById("browser").innerHTML=" Your browser is Chrome";
    }
	
    else if(navigator.userAgent.indexOf("Opera") != -1 )
	{
		document.getElementById("browser").innerHTML="Your browser is Opera";
    }
	
    else if(navigator.userAgent.indexOf("Firefox") != -1 )
	{
       document.getElementById("browser").innerHTML="Your browser is Firefox";
    }
	
    else if((navigator.userAgent.indexOf("MSIE") != -1 ) || (!!document.documentMode == true ))
	{
      document.getElementById("browser").innerHTML="Your browser is Internet Explorer";
    }  
	
	else if((navigator.userAgent.indexOf("Edge") != -1 ) || (!!document.documentMode == true ))
	{
		document.getElementById("browser").innerHTML="your browser is Microsoft Edge";
	}
	
	else if((navigator.userAgent.indexOf("AppleWebKit") != -1 ) || (!!document.documentMode == true ))
	{
		document.getElementById("browser").innerHTML="your browser is Safari";
	}
	
    else
	{
       document.getElementById("browser").innerHTML="Your browser is Unknown";
    }
}// end function browserDetection

/*

******************************************************************
Script 2: Status Bar Message (statusbar.html)
this function shows a message on the status bar
******************************************************************
*/
function statusBar() 
{
  var elem = document.getElementById("myBar");   
  var width = 1;
  var id = setInterval(frame, 10);
  
  function frame()
  {
    if (width >= 100) 
	{
      clearInterval(id);
    } 
	
	else 
	{
      width++; 
      elem.style.width = width + '%'; 
    }
  }
}

/*

/*
/*****************************************************************
Script3a : Vertical Scrolling Text( scroll.html)
this function is used for Vertical Scrolling Text
****************************************************************
*/
var pos=100;
function scrollText() 
{
	pos =pos-1;
    document.getElementById("text").style.top=pos;
    window.setTimeout("scrollText()",30);
}// end function scrollText
/*

/*
/*****************************************************************
Script3b :  Scrolling Text( scrolltext.html)
this function is used for  Scrolling Text
****************************************************************
*/
var message = "Welcome to my Web";
i=0;
function scrollBox() 
{
	i++;
	if(i > message.length)	
	{
	    i = 1;
	}
	document.forms[0].elements[0].value = message.substring(0,i)+"_";
	setTimeout("scrollBox()",100);
}//end function scrollBox
/*
/*****************************************************************
Script 4a: Image Rollover (imagerollover.html)
this function is used for an image rollover
****************************************************************
*/
function changeImage() 
{
    var image = document.getElementById('myImage');
    if (image.src.match("monitori")) 
	{
        image.src = "images/monitor.gif";
    } 
	
	else 
	{
        image.src = "images/monitori.gif";
    }
}// end function changeImage


/*
/*****************************************************************
Script 4b: Text Rollover (textrollover.html)
this function is used for a text rollover
****************************************************************
*/
function mouseOver() 
{
    document.getElementById("text").style.color = "#5b17b5";
}// end function

function mouseOut()
{
    document.getElementById("text").style.color = "#2f0766";
}// end function

function mouseOver2() 
{
    document.getElementById("mytext").style.color = "#5b17b5";
}// end function

function mouseOut2() 
{
    document.getElementById("mytext").style.color = "#2f0766";
}// end function

/*

/*
*******************************************************************
Script 5: Cycling Animations (cyclinganimations.html)
Using Canvas
******************************************************************
*/
//declare variables
var img = new Image();
img.src = 'images/animation.jpg';
var CanvasXSize = 950;
var CanvasYSize = 200;
var speed = 30; //lower is faster
var scale = 1.05;
var y = -4.5; //vertical offset

// Main program
var dx = 0.75;
var imgW;
var imgH;
var x = 0;
var clearX;
var clearY;
var ctx;

img.onload = function() {
    imgW = img.width*scale;
    imgH = img.height*scale;
    if (imgW > CanvasXSize) { 
		x = CanvasXSize-imgW; 
    } // image larger than canvas
    if (imgW > CanvasXSize) { 
		clearX = imgW; 
	} // image larger than canvas
    else { 
		clearX = CanvasXSize; 
	}
    if (imgH > CanvasYSize) { 
		clearY = imgH; 
	} // image larger than canvas
    else {
		clearY = CanvasYSize; 
	}
    //Get Canvas Element
    ctx = document.getElementById('canvas').getContext('2d');
    //Set Refresh Rate
    return setInterval(draw, speed);
}

function draw() {
	//Clear Canvas
    ctx.clearRect(0,0,clearX,clearY);
    //If image is <= Canvas Size
    if (imgW <= CanvasXSize) {
        //reset, start from beginning
        if (x > (CanvasXSize)) {
			x = 0; 
		}
        //draw aditional image
        if (x > (CanvasXSize-imgW)) {
			ctx.drawImage(img,x-CanvasXSize+1,y,imgW,imgH); 
		}
    }
    //If image is > Canvas Size
    else {
        //reset, start from beginning
        if (x > (CanvasXSize)) { 
			x = CanvasXSize-imgW; 
		}
        //draw aditional image
        if (x > (CanvasXSize-imgW)) { 
			ctx.drawImage(img,x-imgW+1,y,imgW,imgH);			
	    }
    }
    //draw image
    ctx.drawImage(img,x,y,imgW,imgH);
    //amount to move
    x += dx;
}// end function draw

 /*
*******************************************************
Script 6:Image Slide Show (slideshow2.html)

***********************************************************
*/
 function slideShow() {
	var imgs = document.getElementById('slideshow').children;
	interval = 2000;
	currentPic = 0;
	imgs[currentPic].style.webkitAnimation = 'fade '+interval+'ms';
	imgs[currentPic].style.animation = 'fade '+interval+'ms';
	var infiniteLoop = setInterval(function(){
		imgs[currentPic].removeAttribute('style');
		if ( currentPic == imgs.length - 1) {
			currentPic = 0;
		} else {
			currentPic++;
		}
	imgs[currentPic].style.webkitAnimation = 'fade '+interval+'ms';
	imgs[currentPic].style.animation = 'fade '+interval+'ms';
}, interval);
}// end function slideShow
/*
*******************************************************
Script 7:Dynamic Frame Update(dynamicframesupdate.html)
this function changes the content of an iframe
***********************************************************
*/
function dynamicFrame() 
{
    var frames = window.frames;
	frames[0].location = "work.html";
    frames[1].location = "work.html";
}// end dynamicFrame

/*
/*****************************************************************
Script 8a: Email Verification(emailverification.html and emailthanks.html)
this function is used for email verification
****************************************************************
*/
function emailVerification(myForm) 
{
	re = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/
	if (re.test(myForm.emailAddr.value)) 
	{
		document.getElementById("email").innerHTML= "Thanks  "+myForm.emailAddr.value;	
	}
	
	else
	{
		alert("Invalid email address")
	}
}//end function emailVerification 


/*
*******************************************************
Script 11:Dynamic Web Page Update(Time)(dynamicwebpageupdate.html)
this function prints the time
***********************************************************
*/
function timeDigtal(){
	var currentTime = new Date();
	var hours = currentTime.getHours();
	var minutes = currentTime.getMinutes();
	var seconds = currentTime.getSeconds();
    document.getElementById("digtime").innerHTML="<b>TIME IS: " + hours + ":" + minutes + " " + ":" + seconds + " " + "</b>";
}//end function timeDigtal

/*
*******************************************************
Script 12:Hit Page Counter(hitcounter.html)
this function prints the time
***********************************************************
*/

function hitCount()
{
	if (localStorage.pagecount){
		localStorage.pagecount=Number(localStorage.pagecount) +1;
	}
	
	else{
		localStorage.pagecount=1;
	}
	document.getElementById("hits").innerHTML=localStorage.pagecount;
}//end hitCount
