-- Contato = (nome, endereco, telefone, e-mail)
type Contato = (String,String,Int,String)
type Agenda = [Contato]

agenda1 :: Agenda
agenda1 =
    [("Jose Silva","Rua 12",99998888,"josesilva12@ufu.br"),
    ("Maria Santos","Rua 26",99887777,"mariasantos26@ufu.br"),
    ("Pedro Rocha","Rua 89",99665555,"pedrorocha89@ufu.br")]


-- procura o email e retorna o nome 
recuperar :: String -> Agenda -> String
recuperar email [] = "Email desconhecido"
recuperar email ((nome1,_,_,email1):cs) =   if (email1==email)
                                            then nome1
                                            else recuperar email cs

{-
    ghci> recuperar "josesilva12@ufu.br" agenda1
    "Jose Silva"
-}