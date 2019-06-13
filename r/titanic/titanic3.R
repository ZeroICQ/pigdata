# Каковы медиана и стандартное отклонение платежей
# (Fare)? Округлите до 2 десятичных знаков.
library("ggplot2")
data <- read.csv("titanic_train.csv")

dev <- round(sd(data$Fare), digits = 2)
med <- round(median(data$Fare), digits = 2)
cm <- data.frame(c(dev, med), row.names = c("deviation", "median"))
pd <- c(dev, med)

qplot(x=rownames(cm), y=pd, geom="col", fill=pd, main ="Fare median and deviation", xlab = "")

med 
dev