# Divide-A.I.---plataforma-de-acompanhamento-e-divisao-de-despesas.
Este repositório contém códigos desenvolvidos pelo nosso grupo na disciplina de Engenharia de Software da UFMG.

# Equipe:

Amanda Alkmim Rezende Teixeira | 2016026655

Gabriel Espeschit | 2015065541

Gustavo Emanuel Faria Araújo | 2017002482

Mateus Dantas Hora | 2015016249

Samuel Souza da Silva | 2016027511

# Informações do Projeto

Link da planilha de controle de atividades e com o gráfico de burndown
https://docs.google.com/spreadsheets/d/1oa4lTubvsyBQJ267jV86poUsJxJh8gfyZkTkxyCqJXQ/edit#gid=1707692041

# Estórias e Tarefas

E1: O Divide A.I. deve possibilitar um usuário criar sua conta, para que possa controlar suas dívidas. Tal conta deve ser criada através de um e-mail a ser verificado, e irá conter informações pessoais do seu dono, como nome, endereço, conta do banco, etc.
	**Story points: 5  --- Total de horas: 26 horas**
* E1.T1: Criar tabelas no banco de dados para cadastro de usuário. **(10 horas - Samuel)**
* E1.T2: Integrar as tabelas com o qt **(4 horas - Amanda)**
* E1.T3: Desenvolver tela de cadastro de usuário. **(2 horas - Samuel)**
* E1.T4: Realizar link com e-mail do usuário (enviar confirmação). **(4 horas - Espeschit)**
* E1.T5: Desenvolver tela de login. **(2 horas - Gustavo)**
* E1.T6: Desenvolver página de Perfil do usuário (nome, endereço, etc.). **(4 horas - Amanda)**

E2: O usuário deve ser capaz de adicionar amigos e criar grupos de despesas. Assim, ele poderá visualizar de maneira ágil suas dívidas, segmentada por grupos e por pessoas.
	**Story points: 5  --- Total de horas: 27 horas**
* E2.T1: Criar tabelas no banco de dados para grupos e despesas. **(4 horas - Samuel)**
* E2.T2: Desenvolver telas para visualização de grupos e amigos. **(3 horas - Espeschit)**
* E2.T3: Desenvolver ferramenta para criação de grupos. **(6 horas - Mateus)**
* E2.T4: Adicionar grupos de despesa padrão. **(6 horas - Gustavo)**
* E2.T5: Desenvolver sistema de localização de usuário no banco de dados. **(4 horas - Mateus)**
* E2.T6: Desenvolver sistema de envio e aceite de convite entre amigos. **(4 horas - Espeschit)**

E3: O usuário deve poder adicionar despesas e classificá-las a partir de grupos de despesa, data, frequência e moeda.
	**Story points: 2  --- Total de horas: 13 horas**
* E3.T1: Inserir botão para criação de nova despesa. **(1 hora - Gustavo)**
* E3.T2: Inserir campo para data da despesa. **(1 hora - Gustavo)**
* E3.T3: Inserir campo de seleção de moeda. **(2 horas - Gustavo)**
* E3.T4: Inserir campo para seleção de categoria da despesa (comida, transporte, etc.).  **(6 horas - Amanda)**
* E3.T5: Inserir campo para despesa recorrente, informando a frequência de cobrança. **(3 horas - Gustavo)**

E4: O usuário deve poder adicionar dívidas entre amigos, inserindo o valor referente à dívida, sua moeda, os pagantes e os devedores. Será possível inserir tanto uma despesa em que o usuário é pagante, quanto devedor, perante confirmação dos envolvidos.
	**Story points: 1  --- Total de horas: 10 horas**
* E4.T1: Inserir botão para criação de nova dívida. **(1 hora - Espeschit)**
* E4.T2: Desenvolver campo para inserir pagantes e devedores (indivíduos ou grupos). **(4 horas - Espeschit)**
* E4.T3: Inserir campo de seleção de moeda. **(1 hora - Amanda)**
* E4.T4: Enviar notificação para todos os envolvidos na despesa sobre seu lançamento. **(4 horas - Mateus)**

E5: O sistema deverá oferecer a opção de simplificar dívidas automaticamente entre grupos, para deixar as transferências de dinheiro mais enxutas. Assim, se João deve pagar Maria, e Maria deve pagar Pedro, a dívida pode ser simplificada para João pagar Pedro.
	**Story points: 3  --- Total de horas: 15 horas**
* E5.T1: Desenvolver sistema matemático para simplificação das dívidas. **(8 horas - Mateus)**
* E5.T2: Adicionar opção de simplificar dívidas automaticamente. **(2 horas - Samuel)**
* E5.T3: Realizar atualização dos valores das dívidas. **(5 horas - Gustavo)**

E6: O usuário deve poder acompanhar seus gastos em uma página exclusiva, que contém um gráfico, dividido por seus grupos e categoria de despesas. Assim, seu controle financeiro será otimizado, sabendo de maneira resumida para quem deve, e em qual âmbito está gastando mais.
	**Story points: 2  --- Total de horas: 11 horas**
* E6.T1: Inserir aba para acompanhamento de gráficos no perfil pessoal. **(2 horas - Samuel)**
* E6.T2: Realizar aquisição de informações nas dívidas gerais pessoais e dos grupos. **(4 horas - Espeschit)**
* E6.T3: Mostrar em um gráfico a porcentagem de cada categoria. **(5 horas - Amanda)**
