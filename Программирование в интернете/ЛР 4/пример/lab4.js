
var x = document.cookie; 
console.log(x);

function logCookies(){
   console.log(document.cookie); 
}
function ColorToCookies(){
    var color = document.getElementById("Color").value,
         opacity = document.getElementById("Range").value;
        date = new Date;
    ButtonBGColor(color,opacity);
    date.setSeconds(date.getSeconds() + 5);
    document.cookie="divOpacity="+opacity+"; expires="+date.toUTCString()+"; path=/";
    date.setSeconds(date.getSeconds() + 5);        
    document.cookie="divColor="+color+"; expires="+date.toUTCString()+"; path=/";

}
function ButtonBGColor(color,opacity){
    var cl = document.getElementById("example");      
    cl.style.backgroundColor=color;
    cl.style.opacity=opacity;    
}
function onload(){
    var c = document.cookie.split(';'),color='#ffffff',colorPattern="divColor=",opacity='1',opacityPattern="divOpacity=";
    //if(c.length>1){
        c.forEach(function(s){       
            if(s.indexOf(colorPattern)>=0){
                color=s.replace(colorPattern,'');
               color=color.replace(' ','');
            }
            else{
                if(s.indexOf(opacityPattern)>=0){
                    opacity=s.replace(opacityPattern,'');
                    opacity=opacity.replace(' ','');
                }

            }
        });
        ButtonBGColor(color,opacity);  
   // }
}
