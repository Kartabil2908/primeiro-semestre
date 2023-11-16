const inputTexto = document.getElementById('enviarMensagem');
const getLocalStorage = () => JSON.parse(localStorage.getItem('usuario')) ?? [];
const socket = io();

const { usuarionome, meuid } = Qs.parse(location.search, { ignoreQueryPrefix: true });
const btnSair = document.getElementById('btnSair');
socket.emit('entrarSala', {usuarionome, meuid});


btnSair.addEventListener('click', function() {
    const sairSala = confirm("Certeza que deseja sair da sala?");

    if(sairSala) {
        socket.emit('sairSala');
        window.location.href = "index.html";
    }
})


inputTexto.addEventListener('keyup', function(e){
    var key = e.key === 'Enter';
    
    if(key && this.value) {
        socket.emit('mensagemChat', this.value);
        this.value = '';
    }
});


function criarElementoHtml(nomeElemento, classeElemento){

    var elemento = document.createElement(nomeElemento);

    for(var classe of classeElemento){
        elemento.classList.add(classe);
    }

    return elemento;

}

function automaticScroll(){
    var elemento = document.getElementById('chat');
    elemento.scrollTop = elemento.scrollHeight;
}

function adicionarNovaMensagem(mensagem) { 
        const usuarioStorage = getLocalStorage();
        var minhaMensagem = false;

        if(mensagem.meuid) {
            minhaMensagem = mensagem.meuid === usuarioStorage.meuId;
        }

        var divMensagem = '';
        var divDetalhes = '';
        var quadroMensagens = document.getElementById('quadro-mensagens');
        var li = criarElementoHtml('li', ['clearfix']);
        var span = criarElementoHtml('span', ['message-data-time']);
        
        if (minhaMensagem) {
            divMensagem = criarElementoHtml('div', ['message', 'other-message', 'float-right']);
            divDetalhes = criarElementoHtml('div', ['message-data','text-right']);
        }
        else{
            var divMensagem = criarElementoHtml('div', ['message', 'my-message']);
            var divDetalhes = criarElementoHtml('div', ['message-data']);    
        }
        
    
        span.innerHTML = (minhaMensagem ? "eu" : mensagem.usuarioNome) + ',' + mensagem.horario;
        divMensagem.innerHTML = mensagem.mensagem;

        divDetalhes.appendChild(span);
        li.appendChild(divDetalhes);
        li.appendChild(divMensagem);
        quadroMensagens.appendChild(li);
        automaticScroll();
}

socket.on('novaMensagem', (mensagem) => {
    adicionarNovaMensagem(mensagem);
});

socket.on('salaUsuarios', ({sala, usuarios}) => {
    document.getElementById('salaId').innerHTML = sala;
    document.getElementById('listaUsuarios').innerHTML = '';

    for(var usuario of usuarios) {
        criarListaUsuario(usuario.nome);
    }
});


function criarListaUsuario(usuarioNome) {
    var listaUsuarios = document.getElementById("listaUsuarios");
    var liUsuario = criarElementoHtml("li", ["clearfix"]);
    var divDescricaoUsuario = criarElementoHtml("div" , ["about"]);
    var divNomeUsuario = criarElementoHtml("div", ["name"]);
    var divStatusUsuario = criarElementoHtml("div", ["status"]);
    var iconeStatus = criarElementoHtml("i", ["fa", "fa-circle", "online"]);

    iconeStatus.innerHTML = "online";
    divNomeUsuario.innerHTML = usuarioNome;

    divStatusUsuario.appendChild(iconeStatus);
    divDescricaoUsuario.appendChild(divNomeUsuario);
    divDescricaoUsuario.appendChild(divStatusUsuario);
    liUsuario.appendChild(divDescricaoUsuario);
    listaUsuarios.appendChild(liUsuario);
}

