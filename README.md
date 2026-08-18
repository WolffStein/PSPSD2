# PSPSD — Programação para Sistemas Paralelos e Distribuídos

Implementações em **C com MPI** desenvolvidas na disciplina de Sistemas Paralelos e Distribuídos (UnB). O foco é o modelo de troca de mensagens: como processos independentes coordenam trabalho sem memória compartilhada.

## O que está implementado

### Comunicação ponto a ponto
| Arquivo | Conceito |
|---|---|
| `01_hello.c` | Inicialização do ambiente MPI, rank e size |
| `02_info.c` | Identificação de processo e host no comunicador |
| `03_send_order.c` | `MPI_Send` / `MPI_Recv` com ordenação determinística |
| `04_recv_any.c` | Recepção não determinística com `MPI_ANY_SOURCE` |
| `05_produtor_consumidor.c` | Produtor–consumidor sobre troca de mensagens |

### Operações coletivas
| Arquivo | Conceito |
|---|---|
| `06_barrier.c` | Sincronização por barreira |
| `07_broadcast.c` | Difusão de dados da raiz para todos os processos |
| `08_gather.c` | Coleta de resultados parciais na raiz |
| `09_scatter.c` | Distribuição de partições de dados entre processos |
| `10_reduce.c` | Redução com operador associativo na raiz |
| `11_allreduce.c` | Redução com resultado replicado em todos os processos |

### Exercícios aplicados
- **`Lista1/q_8`** — *Prefix Scan* paralelo (soma de prefixos distribuída)
- **`Lista1/Questao p2`** — soma de números primos com particionamento entre processos
- Demais pastas `q_*` — exercícios da lista, cada um com enunciado e solução

## Como executar

```bash
mpicc 07_broadcast.c -o broadcast
mpirun -np 4 ./broadcast
```

## Por que este repositório existe

Trabalhar com grandes volumes de dados exige entender o que acontece embaixo das abstrações. Frameworks como Spark escondem particionamento, shuffle e redução atrás de uma API — implementar `scatter`, `gather` e `reduce` na mão em MPI torna essas operações concretas, e muda a forma como você lê um plano de execução distribuído depois.

---

*Disciplina: Programação para Sistemas Paralelos e Distribuídos — Universidade de Brasília.*
