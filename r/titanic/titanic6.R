library("ggplot2")
data <- read.csv("titanic_train.csv")
males  = data[which(data$Sex == "male"),]

#sort(table(males$Name))
#strsplit(males$Name, " ")
#as.character(males[,"Name"][1])
r <- lapply(males[["Name"]], function(x) tail(strsplit(as.character(x), " ")[[1]], 1))

dim(r)

#names(table(r))[as.vector(table(r))==max(table(r))]
#max(table(r))
#See frequency table of all words
sortedNames <- sort(table(as.character(r)), decreasing = TRUE)
sortedNames[1:3]
sn <- sortedNames[1:10]
ggplot(data=data.frame(sortedNames))

qplot(x=rownames(sn), y=sn, geom="col", fill=factor(sn))
