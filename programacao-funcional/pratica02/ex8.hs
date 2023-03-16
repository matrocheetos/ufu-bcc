type Livro = (String, String, String, String, Int)
--           (Código, Título, Autor, Editora, Ano de publicação)

type Aluno = (String, String, String, Int)
--           (Código, Nome, E-mail, Telefone)

type Data = (Int, Int, Int)
type Emprestimo = (String, String, Data, Data, String)
--                (Código do livro, Código do aluno, Data de empréstimo, Data de devolução, Situação)