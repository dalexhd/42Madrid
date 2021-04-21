#!/bin/sh
# Redeclare minukibe home dir.
export MINIKUBE_HOME="/goinfre/aborboll/ft_services_1"
eval $(minikube docker-env)
read -r -p "Are you sure you want to remove deployment $1? [Y/n]" response
REPLY=${REPLY,,} # tolower
if [[ $REPLY =~ ^(yes|y| ) ]] || [[ -z $REPLY ]]; then
	docker build --no-cache -t deployment-$1 srcs/$1
	kubectl rollout restart deployment-$1
fi