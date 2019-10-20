import QtQuick 2.12
import QtCharts 2.3


ChartView {
    id: chart
    title: "Distribuição das despesas"
    titleFont.pointSize: 20
    anchors.fill: parent
    legend.alignment: Qt.AlignBottom
    antialiasing: true

    PieSeries {
        id: pieSeries
        PieSlice{label: "Outros"; value: 0}
    }

    Connections{
        target: graficoCategoria

        onInserirCategoria : {
            if(pieSeries.find(categoria) !== "null")
                pieSeries.remove(categoria)

            pieSeries.append(categoria, valor);
        }

        onApagarDados: pieSeries.clear()
    }
}
