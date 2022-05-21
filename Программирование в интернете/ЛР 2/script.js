const data = [ [148.0, 31.85, 11.0, ' ', ' ', ' ', 244.0, ' ', ' ', ' ', 3.7, 0.0, ' ', 1.5],
               [114.0, 60.38, 57.0, ' ', ' ', ' ', 198.0, '-', '-', 1.89, ' ', '-', '-', 0.9],
               [57.0, 68.57, 0.0, ' ', ' ', ' ', 343.0, ' ', ' ', 0.0, ' ', 11.0, 3.0, 14.3],
               [67.0, 46.67, 0.0, ' ', ' ', ' ', 500.0, ' ', '-', 6.67, ' ', 65.7, 0, 6.7],
               [48.0, 15.2, 0.0, ' ', ' ', ' ', 96.0, ' ', ' ', 0.0, ' ', '-', ' ', 4.0],
               [0.0, 64.29, 0.0, ' ', ' ', ' ', 250.0, '-', ' ', 0.0, ' ', '-', '-',25.8],
               [3.0, 29.41, 6.0, ' ', ' ', ' ', 247.0, '-', '-', 8.63, ' ', ' ', ' ', 1.2],
               [0.0, 46.67, 0.0, ' ', ' ', ' ', 205.0, 0, 0, 0.0, ' ', 0, 0, 0.0],
               [0.5, 3.33, 63.8, ' ',' ', ' ', 43.0, 0, 0, 8.33, 5.7, 0, 0, 0.0],
               [8.0, 71.43, 0.0, ' ', ' ', ' ', 429.0, 3.57, 4.14, 1.79, '-', 0, 2.6, 11.7] ]

function addData() {
    const tbody = document.querySelector('#name')
    const btn_f = document.querySelector('#btn_f')
    const btn_s = document.querySelector('#btn_s')
    for(let i = 0; i < 10; i++) {
        let tr = document.createElement('tr')
        for(let j = 0; j < 14; j++) {
            let td = document.createElement('td')
            const num = data[i][j]
            td.textContent = num
            tr.appendChild(td)
        }
        tbody.appendChild(tr)
        btn_f.style.display = 'none'
        btn_s.removeAttribute('style')
    }
}

function deleteHtmlElement() {
    const tr = document.querySelector('#name').querySelectorAll('tr')
    const thead = document.querySelector('#name_head > tr')
    const btn_s = document.querySelector('#btn_s')
    let id = 0
    console.log(tr[0].childNodes)
    for(let j = 0; j < tr[0].childNodes.length; j++) {
        let counter = 0
        id = j
        for(let i = 0; i < tr.length; i++) {
            let num = '' + tr[i].childNodes[j].textContent
            if(num === '0' || num === ' ' || num === '-') {
                counter++
            }
        }
        if(counter < tr.length){
            for(let m = 0; m < tr.length; m++) {
                num = tr[m].childNodes[id]
                if(num.textContent === ' ' || num.textContent === '-'){
                    num.textContent = '0'   
                }
            }
        }
        if(counter == tr.length){
            let num = thead.childNodes[id]
            thead.removeChild(num)
            for(let m = 0; m < counter; m++) {
                num = tr[m].childNodes[id]
                tr[m].removeChild(num)
            }
            if(tr[1].childNodes.length == j)
                break
            else
                --j
        }
    }
    const td_head_total = document.createElement('td')
    td_head_total.textContent = 'O'
    thead.appendChild(td_head_total)
    let min = 0
    for(let i = 0; i < tr.length; i++) {
        const td_total = document.createElement('td')
        let num = 0
        if(i == 1)
            min += 1
        for(let j = 0; j < tr[0].childNodes.length - min; j++) {
            num += +tr[i].childNodes[j].textContent
            console.log(j, num)
        }
        td_total.textContent = num.toFixed(2)
        td_total.style.backgroundColor = '#09ff00'
        tr[i].appendChild(td_total)
    }
    
    btn_s.style.display = 'none'
}
