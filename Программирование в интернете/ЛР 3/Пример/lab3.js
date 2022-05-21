var myMap = new Map();
class Product {
    constructor(name, natrium, water, jiry) {
        this.name = name;
        this.natrium = natrium;
        this.water = water;
        this.jiry = jiry;
    }

}

function onload() {
    myMap.set('Творог', new Product('Творог', 44.0, 71.7,4));
    myMap.set('Брюква', new Product('Брюква', 10.0, 87.8,6));
    myMap.set('Сельдерей', new Product('Сельдерей', 80.1, 95.24,0));
}


function onz1() {
    // Проверяем поддерживает ли браузер тег <template>
    // проверив наличие аттрибута content у элемента template
    if ('content' in document.createElement('template')) {

        t = document.querySelector('#xmpl-tmplt1'),
            td = t.content.querySelectorAll("td"),
            tb = document.getElementsByTagName("tbody");
        myMap.forEach(function(p) {
            td[0].textContent = p.name;
            td[1].textContent = p.natrium;
            td[2].textContent = p.water;
            td[3].textContent = p.jiry;

            var clone = document.importNode(t.content, true);
            tb[0].appendChild(clone);
        });
        var z2 = document.querySelector('#z2');
        z2.style.visibility = 'initial';
        var z1 = document.querySelector('#z1');
        z1.style.visibility = 'collapse';

    }
    addSelect('#xmpl-meal', 'xmpl-meal-ch1');
    addRadio('#xmpl-meal', 'xmpl-meal-r1');
    addCheck('#xmpl-meal', 'xmpl-meal-ch2');
}

function addCheck(name, id) {
    sp = document.querySelector(name);
    var fs = document.createElement('div');
    fs.setAttribute("id", id);
    fs.setAttribute("class", "check");

    var i = 0;
    myMap.forEach(function(p) {
        var ch = document.createElement('input');
        ch.setAttribute("type", "checkbox");
        ch.setAttribute("class", "entity");
        ch.setAttribute("value", p.name);
        ch.setAttribute("name", id);
        ch.setAttribute("id", id + i);
        var l = document.createElement('label');
        l.setAttribute("for", id + i);
        l.textContent = p.name;

        fs.appendChild(ch);
        fs.appendChild(l);
        i++;

    });

    fs.appendChild(document.createElement('p'));
    sp.appendChild(fs);
}

function addRadio(name, id) {
    sp = document.querySelector(name);
    var fs = document.createElement('div');
    fs.setAttribute("id", id);
    fs.setAttribute("class", "radio");

    var i = 0;
    myMap.forEach(function(p) {

        var r = document.createElement('input');
        r.setAttribute("class", "entity");
        r.setAttribute("type", "radio");
        r.setAttribute("name", id);
        r.setAttribute("id", id + i);
        r.setAttribute("value", p.name);
        var l = document.createElement('label');
        l.setAttribute("for", id + i);
        l.textContent = p.name;

        fs.appendChild(r);
        fs.appendChild(l);
        i++;
    });

    var rng = document.createElement('input');
    rng.setAttribute("class", "quantity");
    rng.setAttribute("type", "number");
    rng.setAttribute("min", "1");
    rng.setAttribute("max", "10");
    rng.setAttribute("value", "1");
    rng.setAttribute("step", "1");
    fs.appendChild(document.createElement('br'));
    fs.appendChild(rng);
    fs.appendChild(document.createElement('p'));
    sp.appendChild(fs);
}

function addSelect(name, id) {
    sp = document.querySelector(name);
    var fs = document.createElement('div');
    fs.setAttribute("id", id);
    fs.setAttribute("class", "select");
    var sel = document.createElement('select');
    sel.setAttribute("class", "entity");
    myMap.forEach(function(p) {
        var opt = document.createElement('option');
        opt.setAttribute("value", p.name);
        opt.textContent = p.name;
        sel.appendChild(opt);
    });
    fs.appendChild(sel);
    var rng = document.createElement('input');
    rng.setAttribute("class", "quantity");
    rng.setAttribute("type", "range");
    rng.setAttribute("min", "1");
    rng.setAttribute("max", "10");
    rng.setAttribute("value", "1");
    rng.setAttribute("step", "1");
    fs.appendChild(document.createElement('br'));
    fs.appendChild(rng);
    fs.appendChild(document.createElement('p'));
    sp.appendChild(fs);
}

function onz2() {
    f = document.querySelector('#f1'),
        d = f.querySelectorAll("div");
    total = new Product("Всего", 0, 0);
    d.forEach(function(p) {
        cs = p.getAttribute("class");
        switch (cs) {
            case 'select':
                q = p.querySelectorAll(".quantity")[0].value;
                m = p.querySelectorAll(".entity")[0].value;
                var n = myMap.get(m);
                total.natrium += q * (n.natrium);
                total.water += q * (n.water);
                break;

            case 'radio':
                q = p.querySelectorAll(".quantity")[0].value;
                ms = p.querySelectorAll(".entity");
                ms.forEach(function(m) {
                    if (m.checked === true) {
                        var n = myMap.get(m.value);
                        total.natrium += q * (n.natrium);
                        total.water += q * (n.water);

                    }
                });
                break;

            case 'check':
                ms = p.querySelectorAll(".entity");
                ms.forEach(function(m) {
                    if (m.checked === true) {
                        var n = myMap.get(m.value);
                        total.natrium += (n.natrium);
                        total.water += (n.water);
                    }
                });
                break;

        };

    });
    if ('content' in document.createElement('template')) {

        t = document.querySelector('#xmpl-tmplt2'),
            th = t.content.querySelectorAll("th"),
            tb = document.getElementsByTagName("tfoot");

        th[0].textContent = total.name;
        th[1].textContent = total.natrium;
        th[2].textContent = total.water;

        var clone = document.importNode(t.content, true);
        tb[0].appendChild(clone);

        z2.style.visibility = 'collapse';

    }
}
onload();