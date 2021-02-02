/*
1.Browser plug-in detection
2.Cycling animations
3.Hit Page Counter
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
*******************************************************************
Script 2: Cycling Animations (cyclinganimations.html)
Using Canvas
******************************************************************
*/
//declare variables
var img = new Image();
img.src = 'images/animation.jpg';
var CanvasXSize = 1520;
var CanvasYSize = 200;
var speed = 1; //lower is faster
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

img.onload = function() 
{
    imgW = img.width*scale;
    imgH = img.height*scale;
	if (imgW > CanvasXSize) 
	{ 
		x = CanvasXSize-imgW; 
	} // image larger than canvas
	
	if (imgW > CanvasXSize) 
	{ 
		clearX = imgW; 
	} // image larger than canvas
	else 
	{ 
		clearX = CanvasXSize; 
	}

	if (imgH > CanvasYSize) 
	{ 
		clearY = imgH; 
	} // image larger than canvas
	else 
	{
		clearY = CanvasYSize; 
	}
    //Get Canvas Element
    ctx = document.getElementById('canvas').getContext('2d');
    //Set Refresh Rate
    return setInterval(draw, speed);
}


function draw() 
{
	//Clear Canvas
    ctx.clearRect(0,0,clearX,clearY);
    //If image is <= Canvas Size
	if (imgW <= CanvasXSize) 
	{
        /*reset, start from beginning*/
		if (x > (CanvasXSize)) 
		{
			x = 0; 
		}
		
        //draw aditional image
		if (x > (CanvasXSize-imgW)) 
		{
			ctx.drawImage(img,x-CanvasXSize+1,y,imgW,imgH); 
		}
    }
    //If image is > Canvas Size
	else 
	{
        /*reset, start from beginning*/
		if (x > (CanvasXSize)) 
		{ 
			x = CanvasXSize-imgW; 
		}

        //draw aditional image
		if (x > (CanvasXSize-imgW)) 
		{ 
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
Script 3: Hit Page Counter
this function prints the time
***********************************************************
*/

function hitCount()
{
	if (localStorage.pagecount)
	{
		localStorage.pagecount=Number(localStorage.pagecount) +1;
	}
	
	else
	{
		localStorage.pagecount = 1;
	}
	document.getElementById("hits").innerHTML = localStorage.pagecount;
}//end hitCount
