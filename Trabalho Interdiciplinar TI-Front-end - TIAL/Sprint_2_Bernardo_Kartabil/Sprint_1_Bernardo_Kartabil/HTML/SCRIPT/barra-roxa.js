document.addEventListener("DOMContentLoaded", function () {
  const apiUrl = "https://jsonserver-proknow.joopaulopaulo33.repl.co/usuarios";
  const userId = 1; // Substitua pelo ID do usuário desejado

  // Função para buscar os dados da API e definir as alturas das barras roxas
  async function fetchData() {
    try {
   
      const response = await fetch(apiUrl);
      if (response.ok) {
        const usuarios = await response.json();

        // Encontrar o usuário com o ID especificado
        const usuario = usuarios.find((user) => user.id === 29);

        if (usuario) {
          // Calcular a soma das despesas a partir de despesas, despesasMes e lazer
          const despesas = parseFloat((usuario.expenses?.despesas || 'R$ 0,00').replace('R$ ', '').replace(',', '.')) || 0;
          const despesasMes = parseFloat((usuario.expenses?.despesasMes || 'R$ 0,00').replace('R$ ', '').replace(',', '.')) || 0;
          const lazer = parseFloat((usuario.expenses?.lazer || 'R$ 0,00').replace('R$ ', '').replace(',', '.')) || 0;

          const totalDespesas = despesas + despesasMes + lazer;

          // Altura máxima da barra roxa
          const alturaMaxima = 80;
          
          // Porcentagens de gastos fictícias para cada dia da semana (ajuste conforme necessário)
          const porcentagensSemanais = {
            domingo: 5,   // Porcentagem de gastos para domingo
            segunda: 10,  // Porcentagem de gastos para segunda
            terca: 15,    // Porcentagem de gastos para terça
            quarta: 20,   // Porcentagem de gastos para quarta
            quinta: 15,   // Porcentagem de gastos para quinta
            sexta: 10,    // Porcentagem de gastos para sexta
            sabado: 25,   // Porcentagem de gastos para sábado
          };

          // Definir a altura da barra roxa para cada dia com base nas porcentagens
          for (const dia in porcentagensSemanais) {
            const porcentagem = porcentagensSemanais[dia];
            const alturaBarra = (totalDespesas * porcentagem / 100) * (alturaMaxima / totalDespesas);
            const barraRoxa = document.getElementById(dia);
            barraRoxa.style.height = `${alturaBarra}px`;
          }

         // Exibir o valor total de despesas na div com id "valor"
         document.getElementById("valor").textContent = `R$ ${(totalDespesas/4).toFixed(2)}`;
        } else {
          console.error("Usuário não encontrado.");
        }
      } else {
        console.error("Erro ao buscar os dados da API.");
      }
    } catch (error) {
      console.error("Ocorreu um erro: ", error);
    }
  }

  // Chame a função para buscar os dados da API e calcular as despesas do usuário
  fetchData();
});


















































/*document.addEventListener("DOMContentLoaded", function () {
  const apiUrl = "https://jsonserver-proknow.joopaulopaulo33.repl.co/usuarios";

  // Função para buscar os dados da API e atualizar as barras no HTML
  async function fetchData() {
    try {
      const response = await fetch(apiUrl);
      if (response.ok) {
        const usuarios = await response.json();

        // Calcular a soma total de totalIncomings a partir de salario, bonus e ativos
        const totalIncomings = usuarios.reduce((total, usuario) => {
          const salario = parseFloat((usuario.incomings.salario || 'R$ 0.00').replace('R$ ', '').replace(',', '.')) || 0;
          const bonus = parseFloat((usuario.incomings.bonus || 'R$ 0.00').replace('R$ ', '').replace(',', '.')) || 0;
          const ativos = parseFloat((usuario.incomings.ativos || 'R$ 0.00').replace('R$ ', '').replace(',', '.')) || 0;

          return total + salario + bonus + ativos;
        }, 0);

        // Definir as porcentagens para cada dia da semana com base no totalIncomings
        const porcentagensPorDia = {
          domingo: (totalIncomings / 4) / 7 * 0.01,  // Ajuste o número de semanas do mês conforme necessário
          segunda: (totalIncomings / 4) / 7 * 0.01,
          terca: (totalIncomings / 4) / 7 * 0.01,
          quarta: (totalIncomings / 4) / 7 * 0.01,
          quinta: (totalIncomings / 4) / 7 * 0.01,
          sexta: (totalIncomings / 4) / 7 * 0.9,
          sabado: (totalIncomings / 4) / 7 * 0.01
        };

        // Atualizar as alturas das barras com as porcentagens calculadas
        const diasDaSemana = ["domingo", "segunda", "terca", "quarta", "quinta", "sexta", "sabado"];
        diasDaSemana.forEach(dia => {
          const barra = document.getElementById(dia);
          barra.style.height = `${porcentagensPorDia[dia]}px`;
        });
      } else {
        console.error("Erro ao buscar os dados da API.");
      }
    } catch (error) {
      console.error("Ocorreu um erro: ", error);
    }
  }

  // Chame a função para buscar os dados da API e atualizar o HTML
  fetchData();
});


*/