/*283.18472*/
/*35% = 99.114652*/
/*40% = 113.2738888*/
/*25% = 70.79618*/

var ZA = 0;
var OA = 0;
var MA = 0;
var flag = -1;
var summAll = 0;

window.onload = function()
{
    document.getElementsByName("lanch")[0].getElementsByTagName("legend")[0].onclick = function()
    {
        var input = document.getElementsByTagName("fieldset")[0].getElementsByTagName("input");
        for(var i = 0; i < input.length; ++i)
        {
            if(input[i].checked == true)
                if(input[i].value <= 99.114652)
                    {
                    alert("Калорийности нормы(35% = 99.114652)\nВы выбрали блюдо: " + input[i].innerText + " с калорийностью: " + input[i].value + "\nВсё ок!");
                    ZA = input[i].value;
                    }
                else
                {
                   alert("Калорийности нормы(35% = 99.114652)\nВы выбрали блюдо: " + input[i].innerText + " с калорийностью: " + input[i].value + "\nНе ок!");
                   ZA = -1;
                }
        }
    var z = Math.floor((Math.random() * (12 - 9)+9 ));
    document.getElementsByName("lanch")[0].getElementsByTagName("p")[0].innerText = z + " часов!";
    }

    document.getElementsByName("Obed")[0].getElementsByTagName("legend")[0].onclick = function ()
    {
       var input = document.getElementsByName("Obed")[0].getElementsByTagName("input");
       var summ = 0;
       for(var i = 0; i < input.length; ++i)
       {
           if(input[i].checked == true)
                summ += Number(input[i].value);
       }
       if (summ <= 113.2738888)
       {
            alert("Калорийности нормы(40% = 113.2738888)\nВы выбрали блюда с калорийностью: " + summ + "\nВсё ок!");
            OA = summ;
       }
        else
        {
            alert("Калорийности нормы(40% = 113.2738888)\nВы выбрали блюда с калорийностью: " + summ + "\nНе ок!");
            OA = -1;
        }

         var z = Math.floor((Math.random() * (15 - 10)+10 ));
        document.getElementsByName("Obed")[0].getElementsByTagName("p")[0].innerText = z + " часов!";
    }

    document.getElementsByName("multi")[0].getElementsByTagName("legend")[0].onclick = function()
    {
        var selected = document.getElementsByName("multi")[0].getElementsByTagName("select");
        var summ = Number(selected[0].value) + Number(selected[1].value);   
    
        
    if (summ <= 70.79618)
    {
        alert("Вы выбрали полдник!\n"+"Калорийности нормы(25% = 70.79618)\nВы выбрали блюда с калорийностью: " + summ + "\nВсё ок!");
        MA = summ;
    }
    else
    {
        alert("Вы выбрали полдник!\n"+"Калорийности нормы(25% = 70.79618)\nВы выбрали блюда с калорийностью: " + summ + "\nНе ок!");
        MA = -1;
        flag = 1;
    }
    var z = Math.floor((Math.random() * (13 -16) + 16));
    document.getElementsByName("multi")[0].getElementsByTagName("p")[0].innerText = z + " часов!";
    }   

    document.getElementsByName("multi")[0].getElementsByTagName("legend")[1].onclick = function()
    {
        var selected = document.getElementsByName("multi")[0].getElementsByTagName("select");
        var summ = Number(selected[0].value) + Number(selected[1].value);   
    
        
    var z = Math.floor((Math.random() * (16 - 13) + 13));
    document.getElementsByName("multi")[0].getElementsByTagName("p")[0].innerText = z + " часов!";
    } 
}


function summ()
{
    var d = new Date();
    var time = d.getTime();
    var x = document.getElementById("text");
    x.innerText = " ";
    var date = Math.floor(d.getDate() / 10) + '' + d.getDate() % 10 + '-' + Math.floor((d.getMonth() + 1) / 10) + '' + (d.getMonth() + 1) % 10 + '-' + d.getFullYear();
    x.innertText = d.getDate();
    if (ZA == -1)
        x.innerText += "Завтрак подобран неправильно!\n";
    if(OA == -1)
        x.innerText += "Завтрак подобран неправильно!\n";
    if (MA == -1)
    {
         if (flag == 1)
            x.innerText += "Полдник подобран неправильно!\n";
    }
    if(ZA >=0 && OA >=0 && MA >=0)
    {
        summAll = Number(ZA) + Number(OA) + Number(MA);
        x.innerText += "Ваша норма на " + date + " составляет: 283.18472 калорий.\nВаш выбор составляет: " + summAll + " калорий.";
    }
   
    x.style.fontFamily = "cursive"
}

