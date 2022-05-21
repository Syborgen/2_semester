
function onz1() {
// Проверяем поддерживает ли браузер тег <template>
// проверив наличие аттрибута content у элемента template
    if ('content' in document.createElement('template')) {
        var col = [
            [2.54, 2, 0, 2],
            [0, 6, 0, 8],
            [3.3, 0, 6, 7]
        ],
            t = document.querySelector('#xmpl-tmplt1'),
            td = t.content.querySelectorAll("td"),
            tb = document.getElementsByTagName("tbody");
        col.forEach(function (ar) {
            var i = 0;
            ar.forEach(function (element) {
                td[i].textContent = element;
                i++;
            });
            var clone = document.importNode(t.content, true);
            tb[0].appendChild(clone); 
        });
         var z2=document.querySelector('#z2');
        z2.style.visibility='initial';
       var z1=document.querySelector('#z1');
        z1.style.visibility='collapse';
       
    } else {
  // необходимо найти другой способ добавить строку в таблицу т.к.
  // тег <template> не поддерживатся браузером
    }
}
function onz2() {
    var t1 = document.querySelector('#xmpl-tmplt1'),
        td1 = t1.content.querySelectorAll("td");
    var tb = document.querySelector('#xmpl-tbd');  
    var tf = document.querySelector('#xmpl-tft');
    var ck = td1.length;
    var sum = Array(ck);
    for (var j = 0; j < ck; j++) {
        sum[j] = 0;  
    };
    var rows = tb.children;
    var i = 0;
    var xsm = 0;
    for (var j = 0; j < rows.length; j++) {       
        xsm = 0;
        for (var i = 0; i <rows[j].childElementCount; i++) {
            sum[i] += parseFloat(rows[j].children[i].textContent);
            xsm  += parseFloat(rows[j].children[i].textContent);
        };
        var xcl = document.importNode(rows[j].children[ck-1], true);
        xcl.textContent = xsm;
        rows[j].appendChild(xcl);
    };
    
    i = 0;
    var t2 = document.querySelector('#xmpl-tmplt2'),
        th2 = t2.content.querySelectorAll("th");
    xsm = 0;
    sum.forEach(function(elem) {
        th2[i].textContent = elem; 
        xsm  += elem;
        i++;
        
    });
    var xcl = document.importNode( th2[ck-1], true);
        xcl.textContent = xsm;
        
    var clone = document.importNode(t2.content, true);
            tf.appendChild(clone);
    tf.children[2].appendChild(xcl);
    var thtr = document.querySelector('#xmpl-th-tr');
    var xcl2 = document.importNode( thtr.children[ck-1], true);
    xcl2.textContent = "ИТОГ";
    thtr.appendChild(xcl2);
  var z2=document.querySelector('#z2');
        z2.style.display='none';                  
  
}