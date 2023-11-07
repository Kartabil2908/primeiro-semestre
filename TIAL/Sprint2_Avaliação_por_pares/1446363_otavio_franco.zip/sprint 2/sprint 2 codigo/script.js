const chatBox = document.getElementById("chat-box");
const messageInput = document.getElementById("message-input");

function addMessage(content, sender) {
  const message = document.createElement("div");
  message.classList.add("message", sender);
  const messageText = document.createElement("div");
  messageText.classList.add("message-text");
  messageText.textContent = content;
  message.appendChild(messageText);
  chatBox.appendChild(message);
  
  // Rolando para a última mensagem
  chatBox.scrollTop = chatBox.scrollHeight;
}

function sendMessage() {
  const messageText = messageInput.value;
  if (messageText.trim() !== "") {
    addMessage(messageText, "sent");
    
    // Simulando uma resposta recebida após um atraso
    setTimeout(function() {
      addMessage("Olá! Ficamos felizes em receber sua mensagem! Nosso horário de funcionamento é 8:00 - 18:00 de segunda à sexta! Em breve um dos nossos colaboradores entrará em contato e te esclarecerá suas dúvidas 😉!" , "received");
    }, 1000);
    
    messageInput.value = "";
  }
}

// Rolar para a última mensagem quando a página carrega
window.onload = function() {
  chatBox.scrollTop = chatBox.scrollHeight;
};
