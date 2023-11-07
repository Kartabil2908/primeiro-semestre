


const data = {
  labels: labels,
  datasets: [
    {
      label: 'Dataset 1',
      data: dataset1Data,
      borderColor: 'red',
      backgroundColor: 'rgba(255, 0, 0, 0.5)',
    },
    {
      label: 'Dataset 2',
      data: dataset2Data,
      borderColor: 'blue',
      backgroundColor: 'rgba(0, 0, 255, 0.5)',
    }
  ]
};

// Restante do código de configuração do gráfico e animação permanece o mesmo

const config = {
  type: 'line',
  data: {
    labels: Utils.months({count: 7}),
    datasets: [{
      label: 'My First Dataset',
      data: [65, 59, NaN, 48, 56, 57, 40],
      borderColor: 'rgb(75, 192, 192)',
      segment: {
        borderColor: ctx => skipped(ctx, 'rgb(0,0,0,0.2)') || down(ctx, 'rgb(192,75,75)'),
        borderDash: ctx => skipped(ctx, [6, 6]),
      },
      spanGaps: true
    }]
  },
  options: {
    responsive: true,
    plugins: {
      legend: {
        position: 'top',
      },
      title: {
        display: true,
        text: 'Chart.js Line Chart - Progressive Line Animation'
      }
    },
    animation: animation  // Aplicando a animação
  }
};



  // Setup
  // Seus dados e ações permanecem inalterados...
  
  // Actions permanecem inalteradas...
  
  // Adicionando a parte de animação ao objeto data
  const totalDuration = 10000;
  const delayBetweenPoints = totalDuration / data.labels.length;
  const previousY = (ctx) => ctx.index === 0 ? ctx.chart.scales.y.getPixelForValue(100) : ctx.chart.getDatasetMeta(ctx.datasetIndex).data[ctx.index - 1].getProps(['y'], true).y;
  
  // Adicionando a parte de animação ao objeto data
  const animation = {
    x: {
      type: 'number',
      easing: 'linear',
      duration: delayBetweenPoints,
      from: NaN, // the point is initially skipped
      delay(ctx) {
        if (ctx.type !== 'data' || ctx.xStarted) {
          return 0;
        }
        ctx.xStarted = true;
        return ctx.index * delayBetweenPoints;
      }
    },
    y: {
      type: 'number',
      easing: 'linear',
      duration: delayBetweenPoints,
      from: previousY,
      delay(ctx) {
        if (ctx.type !== 'data' || ctx.yStarted) {
          return 0;
        }
        ctx.yStarted = true;
        return ctx.index * delayBetweenPoints;
      }
    }
  };
  
  // Criação do gráfico
  const ctx = document.getElementById('myChart').getContext('2d');
  new Chart(ctx, config);
  