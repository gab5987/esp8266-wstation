void le_umidade_temperatura(){
//Leitura de humidade e temperatura podem levar até 250ms! Tempo de resposta(dados prontos para uso) podem levar até 2s
  umidade = dht.readHumidity();
  //Le temperatura em celcius
  temperatura = dht.readTemperature();

  //Checa sanidade dos resultados
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println(F("Falha no sensor!"));
    return;
  }

  //Calcula sensação térmica
  sensacao_termica = dht.computeHeatIndex(temperatura, umidade, false);
}
