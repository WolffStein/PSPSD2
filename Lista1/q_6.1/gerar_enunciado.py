from reportlab.lib.pagesizes import A4
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.units import cm
from reportlab.lib import colors
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, Table, TableStyle, HRFlowable
from reportlab.lib.enums import TA_LEFT, TA_CENTER, TA_JUSTIFY

OUTPUT = "6.1 - Cálculo Paralelo de PI usando Leibniz e OpenMP.pdf"

doc = SimpleDocTemplate(
    OUTPUT,
    pagesize=A4,
    leftMargin=2.5*cm, rightMargin=2.5*cm,
    topMargin=2.5*cm, bottomMargin=2.5*cm
)

styles = getSampleStyleSheet()

BLUE = colors.HexColor("#1a237e")
LIGHT_BG = colors.HexColor("#f5f5f5")

title_style = ParagraphStyle(
    "Title", parent=styles["Title"],
    textColor=BLUE, fontSize=20, spaceAfter=6, leading=26
)
section_style = ParagraphStyle(
    "Section", parent=styles["Heading2"],
    textColor=BLUE, fontSize=12, spaceBefore=14, spaceAfter=4,
    borderPad=2
)
body_style = ParagraphStyle(
    "Body", parent=styles["Normal"],
    fontSize=11, leading=16, spaceAfter=6, alignment=TA_JUSTIFY
)
formula_style = ParagraphStyle(
    "Formula", parent=styles["Normal"],
    fontSize=11, leading=18, spaceAfter=6, alignment=TA_CENTER,
    fontName="Courier"
)
mono_style = ParagraphStyle(
    "Mono", parent=styles["Normal"],
    fontSize=10, leading=14, fontName="Courier",
    backColor=LIGHT_BG, leftIndent=10, rightIndent=10,
    spaceBefore=4, spaceAfter=4
)
author_style = ParagraphStyle(
    "Author", parent=styles["Normal"],
    fontSize=10, alignment=TA_CENTER, textColor=colors.grey, spaceBefore=20
)

def section(title):
    return [
        HRFlowable(width="100%", thickness=1.5, color=BLUE, spaceAfter=2),
        Paragraph(title, section_style),
    ]

story = []

# Título
story.append(Paragraph("Cálculo Paralelo de PI usando<br/>Leibniz e OpenMP", title_style))
story.append(HRFlowable(width="100%", thickness=2, color=BLUE, spaceAfter=10))

# Descrição
story.append(Paragraph(
    "O número <i>&pi;</i> pode ser aproximado pela <b>Série de Leibniz</b>, "
    "uma das séries mais famosas da matemática:",
    body_style
))

story.append(Paragraph(
    "&pi; = 4 &times; ( 1 &minus; 1/3 + 1/5 &minus; 1/7 + 1/9 &minus; ... )",
    formula_style
))

story.append(Paragraph(
    "Formalmente, utilizando notação de somatório:",
    body_style
))

story.append(Paragraph(
    "&pi; = 4 &times; &sum;<super>N-1</super><sub>k=0</sub>  ( &minus;1 )<super>k</super> / ( 2k + 1 )",
    formula_style
))

story.append(Paragraph(
    "Cada termo da série corresponde a uma fração com denominador ímpar alternando de sinal. "
    "Com N = 4 termos, por exemplo:",
    body_style
))

story.append(Paragraph("k=0: +1/1 = 1.0000000000", mono_style))
story.append(Paragraph("k=1: -1/3 = -0.3333333333", mono_style))
story.append(Paragraph("k=2: +1/5 = 0.2000000000", mono_style))
story.append(Paragraph("k=3: -1/7 = -0.1428571429", mono_style))
story.append(Paragraph("Soma = 0.7238095238", mono_style))
story.append(Paragraph("&pi; &asymp; 4 &times; 0.7238095238 = 2.8952380952", mono_style))

story.append(Spacer(1, 6))
story.append(Paragraph(
    "Note que a série de Leibniz converge <b>muito lentamente</b>: são necessários "
    "bilhões de termos para obter casas decimais precisas. Por isso, o uso de "
    "paralelismo com <b>OpenMP</b> é essencial para atingir o resultado em tempo hábil. "
    "Você deverá desenvolver um programa utilizando OpenMP para calcular a "
    "aproximação de <i>&pi;</i> de forma paralela, distribuindo os termos da série "
    "entre múltiplos processos.",
    body_style
))

# Entrada
story += section("Entrada")
story.append(Paragraph(
    "A entrada possui um único inteiro N — o número de termos da série de Leibniz "
    "a serem somados (2 &le; N &le; 10<super>10</super>).",
    body_style
))

# Saída
story += section("Saída")
story.append(Paragraph(
    "A saída deve conter o valor aproximado de <i>&pi;</i> com <b>10 casas decimais</b>.",
    body_style
))

# Restrições
story += section("Restrições")
story.append(Paragraph(
    "&#8226; N pode ser maior que 2 bilhões. Use inteiros de 64 bits (<i>long long</i>).",
    body_style
))
story.append(Paragraph(
    "&#8226; Para os valores fracionários, utilize variáveis de precisão dupla (<i>double</i>).",
    body_style
))
story.append(Paragraph(
    "&#8226; É esperado que, com o uso de paralelismo, seu programa consiga "
    "executar em menos de 6 segundos.",
    body_style
))

# Exemplos
story += section("Exemplo de Entrada 1")
t1 = Table([["4"]], colWidths=[14*cm])
t1.setStyle(TableStyle([
    ("BOX", (0,0), (-1,-1), 0.5, colors.grey),
    ("BACKGROUND", (0,0), (-1,-1), LIGHT_BG),
    ("FONTNAME", (0,0), (-1,-1), "Courier"),
    ("FONTSIZE", (0,0), (-1,-1), 11),
    ("TOPPADDING", (0,0), (-1,-1), 6),
    ("BOTTOMPADDING", (0,0), (-1,-1), 6),
    ("LEFTPADDING", (0,0), (-1,-1), 8),
]))
story.append(t1)

story += section("Exemplo de Saída 1")
t2 = Table([["2.8952380952"]], colWidths=[14*cm])
t2.setStyle(TableStyle([
    ("BOX", (0,0), (-1,-1), 0.5, colors.grey),
    ("BACKGROUND", (0,0), (-1,-1), LIGHT_BG),
    ("FONTNAME", (0,0), (-1,-1), "Courier"),
    ("FONTSIZE", (0,0), (-1,-1), 11),
    ("TOPPADDING", (0,0), (-1,-1), 6),
    ("BOTTOMPADDING", (0,0), (-1,-1), 6),
    ("LEFTPADDING", (0,0), (-1,-1), 8),
]))
story.append(t2)

story += section("Exemplo de Entrada 2")
t3 = Table([["10000000000"]], colWidths=[14*cm])
t3.setStyle(TableStyle([
    ("BOX", (0,0), (-1,-1), 0.5, colors.grey),
    ("BACKGROUND", (0,0), (-1,-1), LIGHT_BG),
    ("FONTNAME", (0,0), (-1,-1), "Courier"),
    ("FONTSIZE", (0,0), (-1,-1), 11),
    ("TOPPADDING", (0,0), (-1,-1), 6),
    ("BOTTOMPADDING", (0,0), (-1,-1), 6),
    ("LEFTPADDING", (0,0), (-1,-1), 8),
]))
story.append(t3)

story += section("Exemplo de Saída 2")
t4 = Table([["3.1415926535"]], colWidths=[14*cm])
t4.setStyle(TableStyle([
    ("BOX", (0,0), (-1,-1), 0.5, colors.grey),
    ("BACKGROUND", (0,0), (-1,-1), LIGHT_BG),
    ("FONTNAME", (0,0), (-1,-1), "Courier"),
    ("FONTSIZE", (0,0), (-1,-1), 11),
    ("TOPPADDING", (0,0), (-1,-1), 6),
    ("BOTTOMPADDING", (0,0), (-1,-1), 6),
    ("LEFTPADDING", (0,0), (-1,-1), 8),
]))
story.append(t4)

story.append(Spacer(1, 20))
story.append(Paragraph("Author: Daniel Sundfeld &lt;daniel.sundfeld@unb.br&gt;", author_style))

doc.build(story)
print(f"PDF gerado: {OUTPUT}")
