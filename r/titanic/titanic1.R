library("ggplot2")
data <- read.csv("titanic_train.csv")
m <- data$Sex

qplot(factor(m), data = data, geom = "bar", fill=data$Sex) + labs(fill="Sex") + xlab("sex")
table(m)
# qplot(factor(m), m, geom = "histogram") 
