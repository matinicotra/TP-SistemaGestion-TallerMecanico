#include <string>
#include "Fecha.h"
#include <iostream>
#include <chrono>
using namespace std;

void Fecha::establecerFechaPorDefecto() {
    auto fechaActual = std::chrono::system_clock::now();
    std::time_t tiempoActual = std::chrono::system_clock::to_time_t(fechaActual);

    std::tm* fechaActualTm = std::localtime(&tiempoActual);

    _dia = fechaActualTm->tm_mday;
    _mes = fechaActualTm->tm_mon + 1;
    _anio = fechaActualTm->tm_year + 1900;
}

bool Fecha::esBisiesto() {
    if ((_anio % 4 == 0 && _anio % 100 != 0) || _anio % 400 == 0) {
        return true;
    }
    return false;
}

void Fecha::agregarDia() {
    int dias[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (esBisiesto()) {
        dias[1]++;
    }

    _dia++;
    if (_dia > dias[_mes-1]) {
        _dia = 1;
        _mes++;

        if (_mes > 12) {
            _mes = 1;
            _anio++;
        }
    }
}

void Fecha::agregarDias(int cantidadDias) {
    if (cantidadDias > 0) {
        for(int i=0; i<cantidadDias; i++)
        {
            agregarDia();
        }
    }
}

Fecha::Fecha() {
    establecerFechaPorDefecto();
}

Fecha::Fecha(int dia, int mes, int anio) {
    _dia = dia;
    _mes = mes;
    _anio = anio;

    if (_dia <= 0 || _mes <= 0 || _anio <= 0 || _mes > 12) {
        establecerFechaPorDefecto();
    }
    else {
        int dias[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (esBisiesto()) {
            dias[1]++;
        }

        if (_dia > dias[_mes - 1]) {
            establecerFechaPorDefecto();
        }
    }
}

int Fecha::getDia() {
    return _dia;
}

int Fecha::getMes() {
    return _mes;
}

int Fecha::getAnio() {
    return _anio;
}

std::string Fecha::toString(std::string formatoFecha) {
    std::string fechaFormateada = "";
    std::string DD = std::to_string(_dia);
    std::string MM = std::to_string(_mes);
    std::string YYYY = std::to_string(_anio);

    // DD/MM/YYYY
    if (_dia < 10) {
        DD = "0" + std::to_string(_dia);
    }
    if (_mes < 10) {
        MM = "0" + std::to_string(_mes);
    }

    if (formatoFecha == "DD/MM/YYYY") {
        fechaFormateada = DD + "/" + MM + "/" + YYYY;
    }
    else if (formatoFecha == "YYYY/MM/DD") {
        fechaFormateada = YYYY + "/" + MM + "/" + DD;
    }
    else {
        fechaFormateada = DD + "/" + MM + "/" + YYYY;
    }
    return fechaFormateada;
}

bool Fecha::operator >=(Fecha aux) {
    string fechaFormateada = "";
    string fechaFormateadaAux = "";

    string DD = to_string(_dia);
    string MM = to_string(_mes);
    string YYYY = to_string(_anio);
    if (_dia < 10) DD = "0" + to_string(_dia);
    if (_mes < 10) MM = "0" + to_string(_mes);

    fechaFormateada = YYYY + MM + DD;

    DD = to_string(aux.getDia());
    MM = to_string(aux.getMes());
    YYYY = to_string(aux.getAnio());
    if (aux.getDia() < 10) DD = "0" + to_string(aux.getDia());
    if (aux.getMes() < 10) MM = "0" + to_string(aux.getMes());

    fechaFormateadaAux = YYYY + MM + DD;

    if (fechaFormateada >= fechaFormateadaAux) return true;

    return false;
}

