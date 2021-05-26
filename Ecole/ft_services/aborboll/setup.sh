#!/bin/sh

# This script setup minikube, builds Docker images, and create pods

SERVICE_LIST="influxdb ftps mysql phpmyadmin grafana wordpress nginx"
# Kill all processes
minikube stop
minikube delete --all
killall -TERM kubectl minikube VBoxHeadless
echo "Starting minikube..."	
# Redeclare minukibe home dir.
export MINIKUBE_HOME="/goinfre/aborboll/ft_services_1"
minikube start --vm-driver=virtualbox --cpus 3 --disk-size=5000MB --memory=3000mb

eval $(minikube docker-env)

minikube addons enable dashboard
minikube addons enable metrics-server
minikube addons enable logviewer
minikube addons enable metallb

kubectl apply -f metallb.yaml

# Build process
minikube dashboard &

for SERVICE in $SERVICE_LIST
do
	docker build -t deployment-$SERVICE srcs/$SERVICE
	kubectl apply -f $SERVICE.yaml
done
