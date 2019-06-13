library("ggplot2")
data <- read.csv("titanic_train.csv")
pclass <- data$Pclass

qplot(factor(pclass), data = data, geom = "bar", fill=data$Sex) + labs(fill="class") + xlab("sex")
table(pclass)
table(data$Sex)
# qplot(factor(m), m, geom = "histogram")
females = data[which(data$Sex == 'female'),]
males = data[which(data$Sex == 'male'),]

qplot(factor(males$Pclass), data = males, geom = "bar", main = "Males", fill=males$Pclass) + labs(fill="class") + xlab("class")
qplot(factor(females$Pclass), data = females, geom = "bar", main = "Females", fill=females$Pclass) + labs(fill="class") + xlab("class")

table(females$Pclass)

table(males$Pclass)

