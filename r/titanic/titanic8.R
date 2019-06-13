library("ggplot2")
data <- read.csv("titanic_train.csv")
dt <- table(data$Age, data$Pclass)

g <- ggplot(df, aes(Var1, Var2)) + geom_point(aes(size = value), colour = "green") + theme_bw() + xlab("") + ylab("")
ggplot(data=data, aes(x=factor(Age), fill=factor(Pclass)))+geom_bar()




