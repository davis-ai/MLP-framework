# MLP-framework


**Nodes** :
x = input,
h = hidden, 
o = output


```mermaid
   
    graph LR;

    %% Input Nodes
    A1((x1 Node))
    A2((x2 Node))

    %% Hidden layer Node
    B1((h1 Node))
    B2((h2 Node))

    %% Output Node
    C1((O Node))
    
    

  A1 --> B1    
  A1 --> B2
  A2 --> B1
  A2 --> B2
  B1 --> C1
  B2 --> C1

```
### Formular

Node = x.w + b

Inputs  : [ x1, x2 ... xn ] 

Weights : [ w1, w2 ... wj ] 

Output  : [ x1.[ w1, w2 ... wj ], x2.[ w1, w2 ... wj ] ... xn.[ w1, w2 ... wj ] ]


























