# QueueMaster

<h3>Implementar a versão 2.0 do sistema de atendimento já realizado, agora com a oferta de 5 opções através de um seletor:</h3>
<ul>
  <li>0. Sair</li>
  <li>1. Gerar senha</li>
  <li>2. Abrir guichê</li>
  <li>3. Realizar atendimento</li>
  <li>4. Listar senhas atendidas</li>
 </ul>
<p>A opção 1 deverá incrementar o controle de senhas, gerando e enfileirando a senha gerada na fila "senhasGeradas".</p>
<p>A opção 2 deverá adicionar, em uma estrutura do tipo Lista, um objeto (struct) contendo o id do guichê e uma fila (senhasAtendidas) para o armazenamento das senhas atendidas por ele</p>
<p>A opção 3 deverá solicitar a digitação do id do guichê que está chamando a senha "da vez", enfileirando-a na fila "senhasAtendidas" do respectivo guichê</p>
<p>A opção 4 deverá solicitar a digitação do id do guichê e, na sequência, listar todas as senhas que foram atendidas por ele
Sempre que o seletor for exibido, informar a quantidade de senhas ainda aguardando atendimento e o número de guichês abertos para atendimento.</p>
<p>O programa só poderá ser encerrado quando a fila "senhasGeradas" estiver vazia. Ao encerrar, informar a quantidade de senhas atendidas.</p>

