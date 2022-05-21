function Load()
{
	document.getElementsByTagName("footer")[0].style.backgroundColor = localStorage.getItem("colorF");
	document.getElementById("1").value = localStorage.getItem("colorF");
	document.getElementsByTagName("aside")[0].style.fontFamily = localStorage.getItem("font");
	document.getElementsByClassName("sec1")[0].style.borderRadius = localStorage.getItem("sec1");
	document.getElementById("5").value = localStorage.getItem("sec1");
	document.getElementsByTagName("header")[0].style.opacity = localStorage.getItem("opacity");
	document.getElementById("6").value = localStorage.getItem("opacity");
	document.getElementsByClassName("sec2")[0].style.borderStyle = localStorage.getItem("sec2");
	document.getElementById("7").value = localStorage.getItem("sec2");
	document.getElementsByClassName("asideDiv")[0].style.boxShadow =  "10px 10px 1px " + localStorage.getItem("colorB");
	document.getElementById("8").value = localStorage.getItem("colorB");
}

window.onload = function()
{
	Load();
}

function Click()//готово
{
	//alert("click");
	var color = document.getElementById("1").value;
	document.getElementsByTagName("footer")[0].style.backgroundColor = color;
	var radiob = document.getElementById("radio").getElementsByTagName("input");
	for(var i=0;i<4;i++)
	{
		if(radiob[i].checked == true)
		{
			var font = radiob[i].value;
			document.getElementsByTagName("aside")[0].style.fontFamily = font;
		}
	}
	document.getElementsByClassName("sec1")[0].style.borderRadius = document.getElementById("5").value;
	document.getElementsByTagName("header")[0].style.opacity = document.getElementById("6").value;
	document.getElementsByClassName("sec2")[0].style.borderStyle = document.getElementById("7").value;
	color = document.getElementById("8").value;
	document.getElementsByClassName("asideDiv")[0].style.boxShadow = "10px 10px 1px " + color;
}

function Save()//ok
{
	localStorage.setItem("colorF", document.getElementById("1").value);
	var radiob = document.getElementById("radio").getElementsByTagName("input");
	for(var i=0;i<4;i++)
	{
		if(radiob[i].checked == true)
		{
			var font = radiob[i].value;
			localStorage.setItem("font", font);
		}
	}
	localStorage.setItem("sec1", document.getElementById("5").value);
	localStorage.setItem("opacity", document.getElementById("6").value);
	localStorage.setItem("sec2", document.getElementById("7").value);
	localStorage.setItem("colorB",document.getElementById("8").value);
}

function Delete()//ok
{
	localStorage.clear();
}
