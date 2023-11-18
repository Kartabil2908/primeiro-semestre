import plotly.express as px
import pandas as pd
import plotly.io as pio

def construir_grafico_1(df_dados):
    df_gasto_total_por_ano = df_dados.groupby('Ano')['valor_liquidado_float'].sum()
    fig = px.line(df_gasto_total_por_ano, x=df_gasto_total_por_ano.index, y=df_gasto_total_por_ano)
    years = sorted(df_gasto_total_por_ano.index.unique())
    fig.update_xaxes(tickmode='array', tickvals=years)
    fig.update_layout(
        title=dict(text="Evolução do gasto público de MG"),
        yaxis_title="Gasto público (R$)",
        xaxis_title="Ano",
    )

    # Salvar o gráfico em um arquivo HTML
    div_grafico = pio.to_html(fig, full_html=False)
    with open("index.html", "w") as html_file:
        html_file.write('<div id="grafico">' + div_grafico + '</div>')

def converter_valor_liquidado_para_float(df_dados):
    list_valores_float = []
    for i in range(len(df_dados)):
        valor_float = float(df_dados.iloc[i]['Valor Liquidado'].replace('.', '').replace(',', '.'))
        list_valores_float.append(valor_float)
    df_dados['valor_liquidado_float'] = list_valores_float
    return df_dados

def construir_df_dados_principal(list_arquivos):
    list_dfs = []
    for nome_arquivo in list_arquivos:
        df_gasto_publico = pd.read_excel(nome_arquivo)
        list_dfs.append(df_gasto_publico)
    return pd.concat(list_dfs)

list_arquivos = [
    './dados/xlsx/consulta_despesas_2019.xlsx',
    './dados/xlsx/consulta_despesas_2020.xlsx',
    './dados/xlsx/consulta_despesas_2021.xlsx',
    './dados/xlsx/consulta_despesas_2022.xlsx',
    './dados/xlsx/consulta_despesas_2023.xlsx'
]

df_dados = construir_df_dados_principal(list_arquivos)
df_dados = converter_valor_liquidado_para_float(df_dados)
construir_grafico_1(df_dados)
