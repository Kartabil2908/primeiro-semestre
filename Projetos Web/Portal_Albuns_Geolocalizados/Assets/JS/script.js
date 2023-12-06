// Cria o mapa e adiciona no elemento de id: map 
mapboxgl.accessToken = 'pk.eyJ1Ijoia2FydGFiaWwiLCJhIjoiY2xwcGx0ejVwMHo2eDJrcWZrajRndzF4aCJ9.8_4iuFiKdb7rssLD4BG-tA';

const map = new mapboxgl.Map({
    container: 'map',
    style: 'mapbox://styles/mapbox/outdoors-v11',
    center: [-43.94401996515573, -19.97414692688077],  // Coordenadas do primeiro álbum
    zoom: 9
});

// Adiciona marcadores para álbuns no mapa
fetch('https://json-server-web-api--bernardokartabi.repl.co/albuns')
    .then(response => response.json())
    .then(albuns => {
        albuns.forEach(album => {
            // Verifica se a URL da capa está definida
            const capaHTML = album.urlcapa ? `<img src="${album.urlcapa}" style="max-width: 100%; max-height: 100%;">` : '';
            
            let popup = new mapboxgl.Popup({ offset: 25 })
                .setHTML(`
                    <h3>${album.nome}</h3>
                    ${capaHTML}
                    <p>${album.descricao}</p>
                    <p>Data: ${album.data}</p>
                `);
                
            const marker = new mapboxgl.Marker({ color: album.cor })
                .setLngLat(album.latlong)
                .setPopup(popup)
                .addTo(map);
        });
    })
    .catch(error => console.error('Erro ao obter dados do servidor:', error));

// Adiciona um marcador com nossa posição no mapa


navigator.geolocation.getCurrentPosition(processarGeo, () => { alert('Erro ao obter localização.'); });
